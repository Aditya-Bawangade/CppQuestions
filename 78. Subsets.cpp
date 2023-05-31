class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() ;
        int lim = (1<<n) ;

        vector<vector<int>> subs(lim) ;
        for(int i = 0 ; i < lim ; i++){
            for(int j = 0 ; j < n ; j++){
                if((i >> j) & 1){
                    subs[i].push_back(nums[j]) ;
                }
            }
        }
        return subs ;
    }
};