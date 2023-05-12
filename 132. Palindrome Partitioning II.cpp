class Solution {
public:
    vector<vector<int>> dp2;
    bool isPal(string &s, int start, int end){
        if(dp2[start][end] != -1){
            return dp2[start][end] ;
        }
        while(start < end){
            if(s[start] != s[end]){
                return dp2[start][end] = 0 ;
            }
            start++ ;
            end-- ;
        }
        return dp2[start][end] = 1 ;
    }
    int util(string s, int start, int end, vector<vector<int>> &dp){
        if(dp[start][end] != -1){
            return dp[start][end] ;
        }
        if(start >= end){
            return dp[start][end] = 0 ;
        }
        if(isPal(s, start, end)){
            return dp[start][end] = 0 ;
        }
        
        int ans = INT_MAX ;
        for(int i = start ; i < end ; i++){
            if(!isPal(s,start,i)){
                continue ;
            }

            int tempans = util(s,start,i,dp) + util(s,i+1,end,dp) + 1 ;
            ans = min(ans, tempans) ; 
        }
        return dp[start][end] = ans ;

    }
    int minCut(string s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1)) ;
        dp2.resize(s.length()+1,vector<int>(s.length()+1,-1)) ;
        return util(s, 0, s.length() - 1, dp) ;
    }
};