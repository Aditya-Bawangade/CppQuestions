class Solution {
public:
    unordered_map<string,bool> dp ;
    bool util(string s1, string s2){
        if(s1 == s2){
            return true ;
        }
        if(s1.size() == 1){
            return s1 == s2 ;
        }
        unordered_map<char,int> f1, f2 ;
        for(char c : s1){
            f1[c]++;
        }
        for(char c : s2){
            f2[c]++;
        }
        for (const auto& [key, value] : f1) {
        auto it = f2.find(key);
        if (it == f2.end() || it->second != value) {
            return false;
        }
    }
        string k = s1 + '*' + s2 ;
        if(dp.find(k) != dp.end()){
            return dp[k] ;
        }
        for(int i = 1 ; i < s1.length() ; i++){
            if((util(s1.substr(0,i),s2.substr(0,i)) && util(s1.substr(i),s2.substr(i))) ||
        (util(s1.substr(0,i),s2.substr(s2.length()-i)) && util(s1.substr(i),s2.substr(0,s2.length()-i))) ){
            return dp[k] = true ;
        }
        }
        
        return dp[k] = false ;
    }
    bool isScramble(string s1, string s2) {
        return util(s1,s2) ;
    }
};