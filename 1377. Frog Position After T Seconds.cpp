class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1) ;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        vector<bool> vis(n+1,0) ;
        vector<double> prob(n+1,0) ;
        queue<int> q ;
        q.push(1) ;
        vis[1] = 1 ;
        prob[1] = 1.0 ;
        while(!q.empty() && t--){
            int sz = q.size() ;
            for(int i = 0 ; i < sz ; i++){
                int node = q.front() ;
                q.pop() ;
                int edgecount = 0 ;
                for(auto v : adj[node]){
                    if(!vis[v]){
                        edgecount++ ;
                    }
                }
                for(auto v : adj[node]){
                    if(!vis[v]){
                        q.push(v) ;
                        vis[v] = 1 ;
                        prob[v] = prob[node]/edgecount ;
                    }
                }
                if(edgecount > 0){
                    prob[node] = 0 ;
                }
            }
        }
        return prob[target] ;
    }
};