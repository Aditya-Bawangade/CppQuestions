class Solution {
public:
    bool util(vector<int> &stones, int start, int k, unordered_map<int,int> &mp,
                vector<vector<int>> &dp){
        if(start == stones.size() - 1){
            return dp[start][k] = 1 ;
        }
        if(dp[start][k] != -1){
            return dp[start][k] ;
        }
        for(int i = k-1 ; i < k + 2 ; i++){
            if(i > 0 && mp.find(stones[start] + i) != mp.end()){
                int ind = mp[stones[start] + i] ;
                if(util(stones, ind, i,mp, dp)){
                    return dp[start][k] = 1 ;
                }
            }
        }
        return dp[start][k] = 0 ;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp ;
        for(int i = 0 ; i < stones.size() ; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(stones.size() + 1, vector<int>(stones.size() + 1, -1)) ;

        return util(stones,0,0,mp,dp) ;
    }
};