class Solution {
public:
    int ans(vector<int> &nums, int i, vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int key = nums[i];
        int currsum = nums[i];
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == key){
            currsum+=nums[idx];
            idx++;
        }
        while(idx  < nums.size() && nums[idx] == key+1){
            idx++;
        }
        return dp[i] = max(currsum + ans(nums,idx,dp), ans(nums,i+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());  
        vector<int> dp(nums.size(),-1);   
        return ans(nums,0,dp);
    }
};