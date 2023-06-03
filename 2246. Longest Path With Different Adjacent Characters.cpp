class Solution {
public:
    int dfs(vector<vector<int>> &adj, string &s, int &ans, int i){
        int max1 = 0 ; 
        int max2 = 0 ; 
        for(int &nbr : adj[i]){
            int cur = dfs(adj, s, ans, nbr) ;
            if(s[i] == s[nbr]) continue ;
            if(cur > max2) max2 = cur ;
            if(max2 > max1) swap(max1, max2) ;
        }
        ans = max(ans, max1 + max2 + 1) ;
        return max1 + 1 ;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size()) ;
        int ans = 0 ; 
        for(int i = 1 ; i < parent.size() ; i++){
            adj[parent[i]].push_back(i) ;
        }
        dfs(adj, s, ans, 0) ;
        return ans ;
    }
};