class Solution {
public:
    // vector<int> possibleNum ;
    vector<vector<int>> adj ;
    vector<int> vec ;
    vector<int> ans ;

    void util(int node, vector<pair<int,int>> count, int h, int par){
        // Max depth element meaning, the minimum closest element ;
        int maxR = INT_MIN ;
        // Index of the closest coprime ;
        int idx ;
        // Iterating over all the possible ancestors; 
        for(int i = 0 ; i < 50 ; i++){
            if(__gcd(i+1, vec[node]) == 1){
                if(maxR < count[i].first){
                    maxR = count[i].first ;
                    idx = count[i].second ;
                }
            }
        }
        if(maxR != INT_MIN){
            ans[node] = idx ;
        }
        // We now put the current node depth and index in ancestor array
        count[vec[node] - 1] = {h, node} ;

        // Iterate over all the adjacent node and also do not visit parent again
        for(auto e : adj[node]){
            if(e == par) continue ;
            util(e, count, h+1, node) ;
        }
        return ;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        // for(int i = 1 ; i <= 50 ; i++){
        //     possibleNum.push_back(i) ;
        // }
        int n = nums.size() ;
        vec = nums ;
        ans.resize(n, -1) ;
        adj.resize(n) ;
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]) ;
            adj[e[1]].push_back(e[0]) ;
        }
        // The height of all ancestors of root is INT_MIN and index of those are -1
        vector<pair<int,int>> temp(50, {INT_MIN, -1}) ;
        util(0,temp,1,-1) ;
        return ans ;
    }
};