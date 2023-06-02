class Solution {
public:
    int mod = 1e9 + 7 ;
    int modPow(int x, unsigned int y, unsigned int m){
        if(y == 0){
            return 1 ;
        }
        long p = modPow(x, y/2, m)%m ;
        p = (p*p)%m ;
        return (y%2) ? (p*x)%m : p ;
    }

    int dfs(vector<vector<int>> &adj, int curr, long long &prod){
        int total_count = 1 ;
        for(auto next : adj[curr]){
            total_count += dfs(adj, next, prod) ;
        }
        prod = prod*total_count % mod ;
        return (curr != 0) ? total_count : prod ;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        vector<vector<int>> adj(prevRoom.size()) ;
        long long fact = 1, prod = 1 ;
        for(int i = 1 ; i < prevRoom.size() ; i++){
            adj[prevRoom[i]].push_back(i) ;
            fact = fact*(i+1) % mod ;
        }
        return fact*modPow(dfs(adj,0,prod), mod-2,mod)%mod ;
    }
};