class Solution {
public:
    int dfs(int i , int j, int zeroes, vector<vector<int>> &grid){
        if(i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == -1){
            return 0 ;
        }
        if(grid[i][j] == 2){
            if(zeroes ==  -1){
                return 1 ;
            }
            else{return 0 ;}
        }
        grid[i][j] = -1 ;
        zeroes-- ;
        
        int ans = dfs(i,j+1,zeroes,grid)+dfs(i+1,j,zeroes,grid)+dfs(i-1,j,zeroes,grid)+dfs(i,j-1,zeroes,grid) ;
        grid[i][j] = 0 ;
        return ans ;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int  a, b, zeroes ;
        zeroes = 0 ;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    a = i ;
                    b = j ;
                }
                if(grid[i][j] == 0){
                    zeroes++ ;
                }
            }
        }
        return dfs(a,b,zeroes,grid) ;
    }
};