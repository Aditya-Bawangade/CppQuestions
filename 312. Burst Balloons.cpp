class Solution {
public:
    long long util(vector<int> &nums, int start, int end, vector<vector<int>> &dp){
        if(start >= end){
            return 0 ;
        }
        if(dp[start][end] != -1){
            return dp[start][end] ;
        }
        long long ans = INT_MIN ;
        for(int i = start ; i < end ; i++){
            long long a = util(nums,start,i,dp) + util(nums,i+1,end,dp) +
            nums[i]*nums[start-1]*nums[end] ;
            ans = max(ans,a) ;
        }
        return dp[start][end] = ans ;
    }


    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1) ;
        nums.push_back(1) ;
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1)) ;
        return util(nums, 1, nums.size() - 1,dp) ;
    }
};