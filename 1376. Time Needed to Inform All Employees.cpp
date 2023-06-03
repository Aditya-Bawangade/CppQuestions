class Solution {
public:
    int maxi = INT_MIN ;
    int dfs(vector<vector<int>> &adj, vector<int> &informTime, int start, int time){
        maxi = max(maxi, time) ;
        for(auto nbr : adj[start]){
            dfs(adj, informTime, nbr, time + informTime[start]) ;
        }
        return maxi ;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n) ; 
        for(int i = 0 ; i < manager.size() ; i++){
            if(i == headID) continue ;
            adj[manager[i]].push_back(i) ;
        }

        return dfs(adj, informTime, headID, 0) ;
        // for(int i = 0 ; i < adj.size() ; i++){
        //     for(int j = 0 ; j < adj[i].size() ; j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl ;
        // }

    }
};