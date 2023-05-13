    class Solution {
public:
    int util(vector<int> &prices, int i, bool buy, int k, vector<vector<vector<int>>> &dp){
        if(i >= prices.size() || k <= 0){
            return 0 ;
        }
        if(dp[i][buy][k] != -1){
            return dp[i][buy][k] ;
        }
        int profit ;
        if(buy == 1){
            profit = max(-prices[i] + util(prices,i+1,0,k,dp), util(prices,i+1,1,k,dp)) ;
        }
        if(buy == 0){
            profit = max(prices[i]+util(prices,i+1,1,k-1,dp),util(prices,i+1,0,k,dp)) ;
        }

        return dp[i][buy][k] = profit ;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1))) ;
        return util(prices,0,1,k, dp) ;
    }
};