class Solution {
public:
    unordered_set<int> visited ; 
    void dfs(int node, vector<vector<int>> &adj, vector<int> &nums){
        for(auto nbr : adj[node]){
            if(!visited.count(nums[nbr])){
                visited.insert(nums[nbr]) ;
                dfs(nbr, adj, nums) ;
            }
        }
        return ;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        vector<vector<int>> adj(parents.size()) ;
        vector<int> ans(parents.size(), 1) ;
        for(int i = 1 ; i < parents.size() ; i++) adj[parents[i]].push_back(i) ;
        int node = -1 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                node = i ;
                break ;
            }
        }
        if(node == -1) return ans ;
        int missing = 1 ;
        while(node != -1){
            visited.insert(nums[node]) ;
            dfs(node, adj, nums) ;
            while(visited.count(missing)) missing++ ;
            ans[node] = missing ;
            node = parents[node] ;
        }
        return ans ;
    }
};