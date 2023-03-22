class Solution {
public:
    int util(vector<int> &nums, int i,vector<int> &dp){ 
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int minima = 10001;
        for(int j = i+1; j <= i+nums[i]; j++){
            minima = min(minima,util(nums,j,dp)+1);
        }
        return dp[i] = minima;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return util(nums,0,dp);
    }
};