class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();
        unordered_map<char,int> mp;
        for(int i = 0; i< size; i++){
            mp[s[i]]++;
        }
        int index = -1;
        for(int i = 0 ; i < size; i++){
            if(mp[s[i]] != -1){
             if(mp[s[i]]==1){
                 index = i;
                 break;
             }  
             mp[s[i]] = -1; 
            }
        }
        return index; 
    }
};