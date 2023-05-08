class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size()) ;
        vector<int> nums(n,0) ;
        vector<int> visited(n,-1) ;

        // ans.push_back(0) ;

        for(int i = 0 ; i < queries.size() ; i++){
            int currCount = 0 ;
            if(visited[queries[i][0]] == -1){
                nums[queries[i][0]] = queries[i][1] ;
                if(queries[i][0] - 1 >= 0 && nums[queries[i][0]] == nums[queries[i][0] - 1]){
                    currCount++ ;
                }
                if(queries[i][0] + 1 < nums.size() && nums[queries[i][0]] == nums[queries[i][0] + 1]){
                    currCount++ ;
                }
                ans[i] = (i>0) ? ans[i-1] + currCount: currCount ;
                visited[queries[i][0]] = 1 ;
            }
            else if(visited[queries[i][0]] == 1){
                // cout<<currCount<<endl;
                if(queries[i][0] - 1 >= 0 && nums[queries[i][0]] == nums[queries[i][0] - 1]){
                    currCount-- ;
                }
                if(queries[i][0] + 1 < nums.size() && nums[queries[i][0]] == nums[queries[i][0] + 1]){
                    currCount-- ;
                }
                nums[queries[i][0]] = queries[i][1] ;
                if(queries[i][0] - 1 >= 0 && nums[queries[i][0]] == nums[queries[i][0] - 1]){
                    currCount++ ;
                }
                if(queries[i][0] + 1 < nums.size() && nums[queries[i][0]] == nums[queries[i][0] + 1]){
                    currCount++ ;
                }
                
                ans[i] = (i>0) ? ans[i-1] + currCount: currCount ;

            }
        }
        // for(auto i : visited){
        //     cout<<i<<endl ;
        // }
        return ans ;

    }
};