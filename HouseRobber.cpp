class Solution {
public:
    int utility(vector<int>& nums, int i, int memo[]){
        if(i>nums.size()-1){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        return memo[i] = max(nums[i]+utility(nums,i+2,memo),utility(nums,i+1,memo));
    }
    int rob(vector<int>& nums, int i = 0) {
        int memoi[nums.size()];
        for(int ia = 0; ia < nums.size(); ia++){
            memoi[ia] = -1;
        }
        return utility(nums,i,memoi);
    }
};