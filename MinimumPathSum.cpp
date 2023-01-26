class Solution {
public:
    int util(vector<vector<int>>& grid, int i, int  j, vector<vector<int>>& dp){
        if(i == grid.size() || j == grid[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == grid.size()-1){
            return dp[i][j] = grid[i][j] + util(grid,i,j+1,dp);
        }
        if(j == grid[0].size()-1){
            return dp[i][j] = grid[i][j] + util(grid,i+1,j,dp);
        }
        return dp[i][j] = grid[i][j] + min(util(grid,i+1,j,dp), util(grid,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid,int i = 0, int  j = 0) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        return util(grid,i,j,dp);
    
    }
};