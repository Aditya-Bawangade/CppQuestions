class Solution {
public:
    int demand[100] ;
    vector<int> adj[100] ;

    int freq(int u, int dest, int p = -1){
        if(u == dest){
            demand[u]++ ;
            return 1 ;
        }
        for(auto v : adj[u]){
            if(v == p) continue ;
            if(freq(v,dest,u)){
                demand[u]++ ;
                return 1 ;
            }
        }
        return 0 ;
    }
    pair<int,int> util(int u, int p, vector<int> &price){
        int half = (price[u]/2)*demand[u] ;
        int notHalf = price[u]*demand[u] ;
        
        for(auto v : adj[u]){
            // to make sure we avoid any repeated calculations I suppose?
            if(v == p) continue ;

            pair<int,int> P = util(v, u, price) ;
            notHalf += min(P.first, P.second) ;
            half += P.second ;
        }
        return {half, notHalf} ;
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
       memset(demand, 0, sizeof(demand)) ;
       for(int i = 0 ; i < n ; i++){
           adj[i].clear() ;
       } 
       for(auto it : edges){
           adj[it[0]].push_back(it[1]) ;
           adj[it[1]].push_back(it[0]) ;
       }
       for(auto trip : trips){
           freq(trip[0],trip[1]) ;
       }
       pair<int,int> ans = util(0,-1,price) ;
       return min(ans.first,ans.second) ;
    }
};