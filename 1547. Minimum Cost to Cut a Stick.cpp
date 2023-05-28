class Solution {
public:
    int util(int start, int end, vector<int> &cuts, int i, int j, vector<vector<int>>& dp){
        if(i > j) return 0 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        int ans = INT_MAX ;
        for(int a = i ; a <= j ; a++){
            int leftcost = util(start, cuts[a], cuts, i, a-1,dp) ;
            int rightcost = util(cuts[a], end, cuts, a+1, j,dp) ;
            int currcost = end - start + leftcost + rightcost ;
            ans = min(ans, currcost) ;
        }
        return dp[i][j] = ans ;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(101, vector<int>(101,-1)) ;
        sort(cuts.begin(),cuts.end()) ;
        return util(0,n,cuts,0,cuts.size()-1,dp) ;
    }
};