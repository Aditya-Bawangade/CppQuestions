class Solution {
public:
    int util(int n, int k, vector<vector<int>> &graph, int mask, vector<int> &dp){
        if(mask == (1<<n) - 1){
            return 0 ;
        }
        if(dp[mask] != -1){
            return dp[mask] ;
        }
        vector<int> indeg(n, 0) ;
        for(int i = 0 ; i < n ; i++){
            if(mask & (1<<i)){
                continue ;
            }
            for(int j = 0 ; j < graph[i].size() ; j++){
                indeg[graph[i][j]]++ ;
            }
        }
        int availableBITS = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0 && !(mask & (1<<i))){
                availableBITS |= 1<<i ;
            }
        }
        int totalNUM = __builtin_popcount(availableBITS) ;
        int ans = n + 1 ;
        if(totalNUM > k){
            for(int s = availableBITS ; s ; s = (s-1)&availableBITS){
                if(__builtin_popcount(s) != k){
                    continue ;
                }
                else{
                    ans = min(ans, 1 + util(n,k,graph,mask|s,dp)) ;
                }
            }
        } 
        else{
            ans = min(ans, 1 + util(n,k,graph,mask|availableBITS,dp)) ;
        }
        return dp[mask] = ans ;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1<<n, -1) ; 
        vector<vector<int>> graph(15) ;
        for(int i = 0 ; i  < relations.size() ; i++){
            relations[i][0]-- ;
            relations[i][1]-- ; 
            graph[relations[i][0]].push_back(relations[i][1]) ;
        }
        return util(n,k,graph,0,dp) ;
    }
};