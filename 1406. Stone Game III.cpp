class Solution {
public:
// Very important Solution
    int dp[50001] = {[0 ... 50000] = INT_MIN/2} ;
    int dfs(vector<int> &sv, int idx){
        if(idx >= sv.size()) return 0 ;

        if(dp[idx] == INT_MIN/2){
            for(auto i = 0, sum = 0 ; i < 3 && idx + i < sv.size() ; i++){
                sum += sv[idx + i] ;
                dp[idx] = max(dp[idx], sum - dfs(sv, idx + i + 1)) ;
            }
        } 
        return dp[idx] ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        auto res = dfs(stoneValue, 0) ;
        return res == 0 ? "Tie" : res < 0 ? "Bob" : "Alice" ;
    }
};