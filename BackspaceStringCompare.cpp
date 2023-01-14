#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s1 = t.length();
        int s2 = s.length();
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i<s2;i++){
            if(s[i]!='#'){
                v1.push_back(s[i]);
            }
            if(s[i]=='#'){
                if(!v1.empty()){
                    v1.pop_back();
                }
                
            }
        }
        for(int i = 0; i<s1;i++){
            if(t[i]!='#'){
                v2.push_back(t[i]);
            }
            if(t[i]=='#'){
                if(!v2.empty()){
                    v2.pop_back();
                }
                
            }
        }
        if(v1 == v2){
            return true;
        }
        return false;
    }
};