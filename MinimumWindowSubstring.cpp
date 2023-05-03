class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int minWindow = t.length();
        int letters = 0;
        int minlen = INT_MAX;
        unordered_map<char,int> mp;
        for(auto word: t){
            mp[word]++;
        } 
        unordered_map<char,int> WindMp;
        for(int fast = 0, slow = 0 ; fast < s.length() ; fast++){
            char trash = s[fast];
            if(mp.find(trash) != mp.end()){
                WindMp[trash]++;
                if(WindMp[trash] <= mp[trash]){
                    letters++;
                }
            }
            if(letters >= t.length()){
                while(mp.find(s[slow]) == mp.end() || WindMp[s[slow]] > mp[s[slow]]){
                    WindMp[s[slow]]--;
                    slow++;
                }
                if(fast-slow+1 < minlen){
                    minlen = fast - slow + 1;
                    ans = s.substr(slow,minlen);
                }
            }
            
        }

       return ans; 
    }
};