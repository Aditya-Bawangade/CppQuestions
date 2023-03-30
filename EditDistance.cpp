class Solution {
public:
    int util(string word1, string word2, int i , int j,vector<vector<int>> &dp){
        // if(i == 0 && j == 0){
        //     return dp[i][j] =0;
        // }
        // if(i < 0 || j < 0){
        //     return 0;
        // }
        if(i == 0){
            return dp[i][j] = j;
        }
        if(j == 0){
            return dp[i][j] = i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(word1[i-1] == word2[j-1]){
            return dp[i][j] = util(word1,word2,i-1,j-1,dp);
        }
        
        else if(word1[i-1] != word2[j-1]){
            int a = util(word1,word2,i-1,j,dp);
            int b = util(word1,word2,i,j-1,dp);
            int c = util(word1,word2,i-1,j-1,dp);
            int a1 = min(a,b);
            int a2 = min(a1,c);
            ans =  a2 + 1;
        }
        return dp[i][j] = ans ;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int> (word2.length()+1,-1));
        int i = word1.length();
        int j = word2.length();
        // if(i > 0){
        //     i--;
        // }
        // if(j > 0){
        //     j--;
        // }
        return util(word1,word2,i,j,dp);
    }
};