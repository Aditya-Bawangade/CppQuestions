const int N = 51 ;
class Solution {
    int f[N][N][2] ;
    int deg[N][N][2] ;
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size() ;
        memset(f,0,sizeof(f)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                deg[i][j][0] = graph[i].size() ;
                deg[i][j][1] = graph[j].size() ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(auto v: graph[0]){
                deg[i][v][1]-- ;
            }
        }
        queue<vector<int>> q ;
        for(int i = 1 ; i < n ; i++){
            f[0][i][1] = f[0][i][1] = 1 ;
            q.push({0,i,0}) ;
            q.push({0,i,1}) ;
        }
        for(int i = 1 ; i < n ; i++){ 
            f[i][i][0] = f[i][i][1] = 2 ;
            q.push({i,i,0}); 
            q.push({i,i,1});
        }
        while(!q.empty()) {
            auto pr = q.front() ;
            q.pop() ;
            int i = pr[0] ;
            int j = pr[1] ;
            int t = pr[2] ;

            if(i == 1 && j == 2 && t == 0){
                break ;
            }

            if(t == 0){
                for(auto v : graph[j]){
                    if(v == 0){
                        continue ;
                    }
                    if(f[i][v][1] != 0){
                        continue ;
                    }
                    if(f[i][j][t] == 2){
                        f[i][v][1] = 2 ;
                        q.push({i,v,1}) ;
                    }else{
                        deg[i][v][1]-- ;
                        if(deg[i][v][1] == 0){
                            f[i][v][1] = 1 ;
                            q.push({i,v,1}) ;
                        }
                    }
                }
            }else{
                for(auto v: graph[i]){
                    if(f[v][j][0] != 0){
                        continue ;
                    }
                    if(f[i][j][t] ==1){
                        f[v][j][0] = 1 ;
                        q.push({v,j,0}) ;
                    }else{
                        deg[v][j][0]-- ;
                        if(deg[v][j][0] == 0){
                            f[v][j][0] = 2 ;
                            q.push({v,j,0}) ;
                        }
                    }
                }
            }
        }
        return f[1][2][0] ;
    }
};