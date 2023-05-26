class Solution {
public:
    int util(vector<vector<int>> &grid, int i, int j, vector<vector<int>>&dp){
        if(i<0 || j < 0 || i >=grid.size()||j>=grid[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j] ;
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return dp[i][j] = 1 ;
        }
        
        if(i>=0 && j>= 0 && i<grid.size() && j<grid[0].size()){
            return dp[i][j] = util(grid,i+1,j,dp) + util(grid,i,j+1,dp) ;
        }
        return dp[i][j] = 0 ;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1)) ;
       vector<vector<int>> grid(m,vector<int>(n,1)) ;
       return util(grid,0,0,dp) ;
    }
};