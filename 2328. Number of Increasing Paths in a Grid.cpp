int Z = 1e9+7 ;
class Solution {
public:
    int util(vector<vector<int>> &grid, int i, int j,vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        vector<int> nrow = {1,-1,0,0} ;
        vector<int> ncol = {0,0,1,-1} ;
        int ans = 1;
        for(int a = 0 ; a < 4 ; a++){
            int ii = i + nrow[a] ;
            int jj = j + ncol[a] ;
            if(ii >= 0 && jj >= 0 && ii < grid.size() && jj <grid[0].size() && grid[ii][jj] < grid[i][j]){
                ans = (ans%Z + util(grid,ii,jj,dp)%Z)%Z ;                
            }
        }
        return dp[i][j] = ans%Z ;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(), -1)) ;
        long long count = 0 ; 
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                count = (count%Z + util(grid,i,j,dp)%Z)%Z;
            }
        }
        return (int)count%Z ;
    }
};