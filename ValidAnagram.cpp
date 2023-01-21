class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int a = s.length();
        int b = t.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0 ; i < a; i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};