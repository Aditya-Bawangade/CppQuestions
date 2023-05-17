class Solution {
public:
    int finans = INT_MAX ;
    void bfs(vector<vector<int>> &adj, int src, int n){
        // int n = adj.size() ;
        vector<int> ans(n, INT_MAX) ;
        vector<int> pred(n, -1) ;

        queue<int> q ;
        ans[src] = 0 ;
        q.push(src) ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            for(int i = 0 ; i < adj[node].size() ; i++){
                if(ans[adj[node][i]] == INT_MAX){
                    ans[adj[node][i]] = 1 + ans[node] ;
                    pred[adj[node][i]] = node ;
                    q.push(adj[node][i]) ;
                }
                else if(pred[adj[node][i]] != node && pred[node] != adj[node][i]){
                    finans = min(finans, ans[adj[node][i]] + ans[node] + 1);
                }
            }
        }
        
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ;
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
        }
        for(int i = 0 ; i < n ; i++){
            bfs(adj, i, n) ;
        }
        return (finans == INT_MAX) ? -1 : finans ;
    }
};