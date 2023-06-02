class Solution {
public:
    int dfs(vector<vector<int>> &adj, int start, bitset<100> &vis){
        if(!vis[start]){
            vis[start] = true ;
            for(int neighbor : adj[start]){
                dfs(adj, neighbor, vis) ;
            }
        }
        return vis.count() ;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size()) ;
        for(int i = 0 ; i < bombs.size() ; i++){
            for(int j = 0 ; j < bombs.size() ; j++){
                long long dist = (pow((bombs[i][0] - bombs[j][0]),2) + pow((bombs[i][1] - bombs[j][1]),2)) ; 
                long long r = (long long)bombs[i][2]*bombs[i][2] ;
                if(dist <= r){
                    adj[i].push_back(j);
                }
            }
        }
        // for(int i = 0 ; i < adj.size() ; i++){
        //     for(int j = 0 ; j < adj[i].size() ; j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl ;
        // }
        int ans = 0 ;
        for(int i = 0 ; i < bombs.size() && ans < bombs.size() ; i++){
            // cout<<i<<endl ;
            ans = max(ans, dfs(adj, i, bitset<100>() = {})) ;
        }
        return ans ;
    }
};