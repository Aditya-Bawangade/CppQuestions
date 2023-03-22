class Solution {
public:
    bool util(vector<int> &nums, int i,vector<int> &dp){
      if(i == nums.size()-1){
        return true;
      }
      if(dp[i] == 1 || dp[i] == 0){
       return dp[i];
     }
      int lim = i + nums[i];
      for(int j = i+1; j <= lim; j++){
            if(util(nums,j,dp)){
                return dp[i] = true;
            }   
      }        
      return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return util(nums,0,dp);
    }
};