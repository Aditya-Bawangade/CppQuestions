
#include <bits/stdc++.h> 
int util(unordered_map<char, int> &mp){
    int ans = 0 ;
    for(auto it : mp){
        if(it.second > 0){
            ans += 1 ;
        }
    }
    return ans ;
}
int getLengthofLongestSubstring(string s, int k) {
    unordered_map<char, int> mp ;
    for(char i = 'a' ; i <= 'z' ; i++){
        mp[i] = 0 ;
    }
    int start = 0 ;
    int ans = 0 ;
    for(int i = 0 ; i < s.length() ; i++){
        mp[s[i]]++ ;
        while(util(mp) > k){
            mp[s[start]]-- ;
            start++ ;
        }
        ans = max(ans, i - start + 1) ;
    }
    return ans ;
}
