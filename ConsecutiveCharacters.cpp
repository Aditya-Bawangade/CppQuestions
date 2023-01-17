class Solution {
public:
    int maxPower(string s) {
        int maxendhere = 0;
        int maxsofar = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i+1] == s[i]){
                maxendhere++;
                if(maxsofar<maxendhere){
                    maxsofar = maxendhere;
                }
            }
            if(s[i+1] != s[i]){
                maxendhere = 0;
            }

        }
        return 1 + maxsofar;
    }
};