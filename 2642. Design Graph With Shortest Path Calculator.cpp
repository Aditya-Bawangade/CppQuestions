class Graph {
    int n ;
    vector<vector<int>> adj ;
public:
    
    Graph(int num, vector<vector<int>>& edges) {
        n = num ;
        adj.resize(num+1, vector<int>(num+1,0)) ;
        for(int  i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]][edges[i][1]] = edges[i][2] ;
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]][edge[1]] = edge[2] ;
        return ;
    }
    int dijkstra(int node1, int node2){
        vector<int> ans(n, INT_MAX) ;
        ans[node1] = 0 ;
        priority_queue<pair<int,int>> q ;
        q.push({node1, 0}) ;
        while(!q.empty()){
            pair<int,int> pr = q.top() ;
            q.pop() ;
            for(int i = 0 ; i < n ; i++){
                if(adj[pr.first][i] != 0){
                    int w = adj[pr.first][i] ;
                    if(pr.second + w < ans[i]){
                        ans[i] = pr.second + w ;
                        q.push({i,pr.second+w}) ;
                    }
                }
            }
        }
        return (ans[node2] != INT_MAX) ? ans[node2] : -1;
    }
    int shortestPath(int node1, int node2) {
        // if(node1 == node2) return 0 ;
        return dijkstra(node1,node2) ;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */