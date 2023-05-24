    int dfs(vector<vector<int>> &A, int i, int j, vector<vector<int>> &dp){
    if(dp[i][j] != -1){
        return dp[i][j] ;
    }
    if(i == A.size()-1 && j == A[0].size() - 1 && A[i][j] == 0){
        return dp[i][j] = 1 ;
    }
    int ans = 0 ;
    if(i >= 0 && j >= 0 && i < A.size() && j < A[0].size() && A[i][j] == 0){
        ans += dfs(A,i+1,j,dp) + dfs(A,i,j+1,dp) ;
        return dp[i][j] = ans ;
    }
    return dp[i][j] = ans ;
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size() ;
    int m = A[0].size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1)) ;
    return dfs(A, 0, 0, dp) ;
}
