class Solution {
public:
    int util(vector<int>& piles, vector<vector<int>>& dp, vector<int> &sums, int i, int m){
        if(i == piles.size()) return 0 ;
        if(piles.size() - i <= 2*m) return sums[i] ;
        if(dp[i][m]) return dp[i][m] ;

        int mini = INT_MAX ;
        for(int j = 1 ; j <= 2*m ; j++){
            mini = min(mini, util(piles,dp,sums,i+j,max(j,m))) ;
        }
        return dp[i][m] = sums[i] - mini ;
    }
    int stoneGameII(vector<int>& piles) {
       if(piles.empty()){
           return 0 ;
       }
       vector<int> sums(piles.size(),0) ;
       sums[piles.size()-1] = piles[piles.size()-1] ;
       for(int i = piles.size() - 2 ; i >= 0 ; i--){
           sums[i] = sums[i+1] + piles[i] ;
       }
       vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0)) ;
       
       return util(piles,dp,sums,0,1) ;
    }
};