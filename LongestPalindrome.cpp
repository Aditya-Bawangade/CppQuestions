class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(int i = 0 ; i < s.length(); i++){
            mp[s[i]]++;
        }
        int singlecount = 0;
        int oddcount = 0;
        for(auto x : mp){
            if(x.second%2 != 0){
                oddcount++;
            }
        }
        int ans;
        if(oddcount == 0){
            ans = s.length(); 
            return ans;
        }
        ans = s.length() - oddcount + 1;
        return ans;
    }
};