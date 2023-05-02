class Solution {
public:
    int longestValidParentheses(string s) {
        int finans = 0;
        vector<int> dp(s.length()+1,0);

        for(int i = 1; i < s.length() ; i++){
            if(s[i] == ')' && s[i-1] == '('){
                dp[i] = (i >= 2) ?dp[i-2]+2 : 0+2;
            }
            else if(s[i] == ')' && s[i-1] == ')'){
                if(i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
                    dp[i] = (i - dp[i-1] - 2 >= 0) ?(dp[i-1] + dp[i - dp[i-1] - 2] + 2): dp[i-1] + 2;
                }
            }
            finans = max(finans, dp[i]);
        }
        return finans;
    }
};