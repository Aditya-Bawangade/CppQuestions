#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
           for(int j = 0; j < grid[i].size(); j++){
               int p = 0;
               if(grid[i][j] == 1){
                   if(i>=1){
                       if(grid[i-1][j] == 0){
                       p++;
                   }
                   }
                   if(i < (grid.size() - 1)){
                        if(grid[i+1][j] == 0){
                       p++;
                   }
                   }
                  if(j>=1){
                       if(grid[i][j-1] == 0){
                       p++;
                   }
                  }
                  if(j<(grid[i].size()-1)){
                      if(grid[i][j+1] == 0){
                       p++;
                   }
                  }
                   if(i == 0){
                       p++;
                   }
                   if(i == (grid.size()-1)){
                       p++;
                   }
                   if(j == 0){
                       p++;
                   }
                   if(j == (grid[i].size()-1)){
                       p++;
                   }
                  
                   
               }
               perimeter += p;
           }
           
       }
       return perimeter;
    }
};