class Solution {
public:
    int util(vector<int> &nums){
        stack<int> stk ;
        int i = 0 ;
        int ans  = INT_MIN ;

        int top ;
        while(i < nums.size()){
            if(stk.empty() || nums[stk.top()] <= nums[i]){
                stk.push(i) ;
                i++ ;
            }
            else{
                top = stk.top() ;
                stk.pop() ;
                int area = nums[top]*((stk.empty()) ? i : i - stk.top() - 1) ;
                ans = max(ans, area) ;
                
            }
        }
        while(!stk.empty()){
            top = stk.top() ;
            stk.pop() ;
            int area = nums[top]*((stk.empty()) ? i : i - stk.top() - 1) ;
            ans = max(ans, area) ;
        }
        return ans ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> nums(matrix.size(),vector<int>(matrix[0].size(),-1)) ;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                int s = (matrix[i][j]) - '0' ;
                nums[i][j] = s ;
            }
        }
        vector<int> v = nums[0] ;
        int ans = util(v) ;
        // cout<<ans<<endl ;
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[0].size() ; j++){
                if(nums[i][j] == 1){
                    v[j]++ ;
                }
                else{
                    v[j] = 0 ;
                }
            }
            ans = max(ans,util(v)) ;
        }
        return ans ;
    }
};