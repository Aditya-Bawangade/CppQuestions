class Solution {
public:
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j] ; 
        }
        int n = matrix.size() ;
        int m = matrix[0].size() ; 

        int nrow[] = {-1,0,1,0} ;
        int ncol[] = {0,1,0,-1} ;

        int maxim = 0 ;
        for(int k = 0 ; k < 4 ; k++){
            int nerow = nrow[k] + i ;
            int necol = ncol[k] + j ;

            if(nerow >= 0 && necol >= 0 && nerow < n && necol < m && matrix[nerow][necol] > matrix[i][j]){
                maxim = max(maxim, 1 + dfs(matrix, nerow, necol,dp));
            }
        }
        return dp[i][j] = maxim ;

        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0 ; 
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1)) ;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                ans = max(ans, dfs(matrix,i,j,dp)) ; 
            }
        }
        return ans + 1 ;
    }
};                      