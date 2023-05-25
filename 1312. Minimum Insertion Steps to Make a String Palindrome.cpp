class Solution {
public:
    bool ispal(string s){
        int i = 0 ;
        int n = s.length() - 1 ;
        while(i <= n){
            if(s[i] != s[n-i]) return false ;
            i++ ;
        }
        return true ;

    }
    int util(string &s, int i, int j, vector<vector<int>> &dp){
        if(i >= j){
            return 0 ;
        } 
        if(dp[i][j] != -1) return dp[i][j] ;
        if(s[i] == s[j]) {
            return dp[i][j] = util(s,i+1,j-1, dp) ;
        }
        int a = util(s,i+1,j, dp) + 1 ;
        int b = util(s,i,j-1, dp) + 1 ;
        // int c = util(s,i+2,j-1, dp) + 2 ;
        // int d = util(s,i+1,j-2,dp) + 2 ;
        return dp[i][j] = min(a,b) ;
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length()+1, -1)) ;
        int j = s.length() - 1 ;
        int ans = util(s, 0, j, dp) ;
        return ans ;
    }
};