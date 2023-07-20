#include <bits/stdc++.h> 

void dfs(vector<vector<int>> &arr, int n, int i, int j, string way, vector<string> &ans, vector<vector<int>> &vis){
    if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == 1 || arr[i][j] == 0) return ;

    if(i == n - 1 && j == n - 1){
        ans.push_back(way) ;
        way.pop_back() ;
        return ;
    }
     vis[i][j] = 1 ;

     dfs(arr, n, i + 1, j, way + 'D', ans, vis) ;
     dfs(arr, n, i - 1, j, way + 'U', ans, vis) ;
     dfs(arr, n, i, j + 1, way + 'R', ans, vis) ;
     dfs(arr, n, i, j - 1, way + 'L', ans, vis) ;

     vis[i][j] = 0 ;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    string way = "" ;
    vector<string> ans ;
    if(arr[n-1][n-1] == 0) return ans ;
    vector<vector<int>> vis(n, vector<int>(n, 0)) ;
    if(arr[0][0] == 1){
        dfs(arr, n, 0, 0, way, ans, vis) ;
    }
    sort(ans.begin(), ans.end()) ;
    return ans ;
}