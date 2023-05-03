class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length() ;
        int n = p.length() ;
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1, false));

        dp[0][0] = 1;
        for(int i = 1 ; i < n + 1; i++){
            if(p[i-1] == '*'){
                dp[0][i] = dp[0][i-1];
            }
        }
        for(int i = 1; i < m + 1 ; i++){
            for(int j = 1; j < n + 1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j -1] == '*'){
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                    // cout<<"DUDE"<<endl<<dp[i][j]<<endl;
                    
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        // for(int i = 0 ; i < dp.size(); i++){
        //     for(int j = 0 ; j < dp[0].size() ; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];


    }
};