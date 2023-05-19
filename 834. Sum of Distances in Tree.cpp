class Solution {
public:
    vector<vector<int>> adj ;
    vector<int> numNodes, ans ;

    void dfs(int i, int p = -1){
        for(auto u : adj[i]){
            if(u == p) continue ;
            dfs(u,i) ;
            numNodes[i] += numNodes[u] ;
            ans[i] += ans[u] + numNodes[u] ;
        }
        numNodes[i] += 1 ;
    }
    void dfs2(int i, int n, int p = -1){
        for(auto u : adj[i]){
            if(u == p) continue ;
            ans[u] = ans[i] - numNodes[u] + n - numNodes[u] ;
            dfs2(u,n,i) ;
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n) ;
        for(int i = 0 ; i < n-1 ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
        }
        ans.resize(n) ;
        numNodes.resize(n) ;
        dfs(0) ;
        dfs2(0,n) ;
        return ans ;
    }
};