class Solution {
public:
    int dp[1000] = {}, last[1000] = {} ;
    int dfs(vector<int> &nums, vector<vector<int>> &adj, int i,  int par, int &ids){
        int id = ids++, res = nums[i] ;
        for(auto child : adj[i]){
            if(child != par){
                res ^= dfs(nums, adj, child, i, ids) ;
            }
        }
        last[id] = ids ;
        return dp[id] = res ;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int ids = 0 ;
        int res = INT_MAX ;
        vector<vector<int>> adj(nums.size()) ;
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]) ;
            adj[edge[1]].push_back(edge[0]) ;
        }
        int all = dfs(nums, adj, 0, -1, ids) ;
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = i + 1 ; j < nums.size() ; j++){
                int p1 = (j < last[i] ? all ^ dp[i] : all ^ dp[i] ^ dp[j]) ;
                int p2 = (j < last[i] ? dp[i] ^ dp[j] : dp[i]) ;
                res = min(res, max({p1, p2, dp[j]}) - min({p1, p2, dp[j]})) ;
            }

        }
        return res ;
    }
};