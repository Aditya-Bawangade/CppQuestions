class Solution {
    unordered_map<string,vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        vector<string> ans ;
        for(auto w : wordDict){
            if(s.substr(0,w.length()) == w){
                if(w.length() == s.length()){
                    ans.push_back(w);
                }
                else{
                    vector<string> temp = wordBreak(s.substr(w.length()),wordDict);
                    for(auto ww : temp){
                        ans.push_back(w + " " + ww);
                    }
                }
            }
        }
        return dp[s] = ans;
    }
};