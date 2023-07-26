#include <bits/stdc++.h> 
string smallestWindow(string s, string x)
{
    // Write your code here.
    string ans = "" ;
    int minWindow = x.length() ;
    int letters = 0 ;
    int minLen = INT_MAX ;
    unordered_map<char, int> mp ;
    for(auto word : x){
        mp[word]++ ;
    }

    unordered_map<char, int> WindMp ;
    for(int fast = 0, slow = 0 ; fast < s.length() ; fast++){
        char ch = s[fast] ;
        if(mp.find(ch) != mp.end()){
            WindMp[ch]++ ;
            if(WindMp[ch] <= mp[ch]){
                letters++ ;
            }
        }

        if(letters == x.length()){
            while(mp.find(s[slow]) == mp.end() || WindMp[s[slow]] > mp[s[slow]]){
                WindMp[s[slow]]-- ;
                slow++ ;
            }
            if(fast - slow + 1 < minLen){
                minLen = fast - slow + 1 ;
                ans = s.substr(slow, minLen) ;
            }
        }

    }
    return ans ;

}