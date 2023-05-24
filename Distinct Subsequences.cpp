int util(string A, string B, vector<vector<int>> &dp){
    int m = A.length() ;
    int n = B.length() ;
    for(int i = 0 ; i <= m ; i++) dp[i][0] = 1 ;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            dp[i][j] = dp[i-1][j] ;
            if(A[i-1] == B[j-1]){
                dp[i][j] += dp[i-1][j-1] ;
            }
        }
    }
    return dp[m][n] ;
}
int Solution::numDistinct(string A, string B) {
    if(A == B){
        return 1 ;
    }
    int m = A.length() ;
    int n = B.length() ;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0)) ;
    return util(A, B, dp) ;
    
}
