class Solution {
public:
    bool bfs(int val, vector<vector<int>> &adj, vector<int> q, vector<int> n,
    vector<int> cnt){
        while(!q.empty()){
            vector<int> q1 ;
            for(auto i : q){
                if(n[i] > val){
                    return false ;
                }
                for(auto j : adj[i]){
                    n[j] += (n[i] < val) ? n[i] : 0 ;
                    if(--cnt[j] == 1){
                        q1.push_back(j) ;
                    }
                }
            }
            swap(q, q1) ;
        }
        return true ;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size() ;
        int sum = accumulate(nums.begin(), nums.end(), 0) ;
        if(sum % n == 0 && all_of(nums.begin(), nums.end(), [&](int v){ return v == sum/n ;}) ){
            // if all nodes are of the same value 
            return n - 1 ;
        }
        vector<vector<int>> adj(n) ;
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]) ;
            adj[e[1]].push_back(e[0]) ;
        }
        vector<int> q, cnt(n) ;
        for(int i = 0 ; i < n ; i++){
            cnt[i] = adj[i].size() ;
            if(adj[i].size() == 1){
                // pushing the leaves in the queue
                q.push_back(i) ;
            }
        }
        for(int i = n - 1 ; i > 1 ; i--){
            if(sum % i == 0 && bfs(sum/i, adj, q, nums, cnt)){
                return i - 1 ;
            }
        }
        return 0 ;

    }
};