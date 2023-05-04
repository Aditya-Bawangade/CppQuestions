class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // A complicated but O(n) one pass solution 
        int ans = INT_MIN ;
        int area = 0 ;
        int i = 0 ;
        int num = heights.size() ;
        stack<int> stk ;
        int top;
        while( i < num ){
            if(stk.empty() || heights[stk.top()] <= heights[i]){
                stk.push(i);
                i++;
            }
            else{
                top = stk.top();
                stk.pop();
                area = heights[top] * ((stk.empty()) ? i : i - stk.top() - 1);
                ans = max(ans, area) ;
            }
        }
        while(!stk.empty()){
            top = stk.top() ;
            stk.pop();
            area = heights[top]*((stk.empty()) ? i : i - stk.top() - 1);
            ans = max(ans,area);
        }

        return ans;
        // int ans = 0;
        // for(int i = 0 ; i < heights.size() ; i++){
        //     int left = 0 ;
        //     int right = 0 ;
            
        //     int j = i ;
        //     while( j >= 0 && heights[j] >= heights[i]){
        //         left++;
        //         j--; 
        //     }
        //     j = i ;
        //     while( j < heights.size() && heights[j] >= heights[i]){
        //         right++;
        //         j++;
        //     }
        //     // cout<<left<<right<<i<<endl;
        //     ans = max(ans, heights[i]*(left+right-1));

        // }
        // return ans;
    }
};