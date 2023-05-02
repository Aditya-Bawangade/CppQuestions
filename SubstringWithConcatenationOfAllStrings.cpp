class Solution {
public:

    bool exists(unordered_map<string,int> mp, int wordSize, string window){
        for(int i = 0; i < window.size(); i += wordSize){
            string word = window.substr(i,wordSize);
            if(!mp[word]){
                return false;
            }
            mp[word]--;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int windowSize = words.size()*words[0].size();
        if(s.size() < windowSize){
            return {};
        }
        vector<int> ans;
        unordered_map<string,int> mp;

        for(auto word: words){
            mp[word]++;
        }

        for(int i = 0 ; i <= s.size() - windowSize ; i++){
            if(exists(mp,words[0].size(),s.substr(i, windowSize))){
                ans.push_back(i);
            }
        }
        return ans;
    }
};