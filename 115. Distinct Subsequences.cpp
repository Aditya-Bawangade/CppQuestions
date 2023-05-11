class Solution {
public:
    
    int numDistinct(string s, string t) {
        vector<vector<unsigned>> dp(t.length() + 1 ,vector<unsigned>(s.length() + 1, 0)) ;
        for(int i = 0 ; i < dp[0].size() ; i++) dp[0][i] = 1 ;
        for(int i = 1 ; i < dp.size() ; i++){
            for(int j = 1 ; j < dp[0].size() ; j++){
                dp[i][j] = dp[i][j-1] + ((t[i-1] == s[j-1]) ? dp[i-1][j-1] : 0) ;
            }
        }
        return dp[t.length()][s.length()] ; 
    }
};