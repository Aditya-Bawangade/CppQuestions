class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        vector<vector<pair<int,int>>> graph(n) ;
        for(auto &g : meetings){
            graph[g[0]].push_back({g[1],g[2]}) ;
            graph[g[1]].push_back({g[0],g[2]}) ;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;
        vector<int> vis(n) ;
        pq.push({0,0}) ;
        pq.push({0,fp}) ;
        while(!pq.empty()){
            auto [t,x] = pq.top() ;
            pq.pop() ;
            if(vis[x]){
                continue ;
            }
            vis[x] = 1 ;
            for(auto &it : graph[x]){
                if(vis[it.first]) continue ;
                if(it.second>=t){
                    pq.push({it.second,it.first}) ;
                }  
            }
        }
        vector<int> ans ;
        for(int i = 0 ; i < vis.size() ; i++){
            if(vis[i]){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};