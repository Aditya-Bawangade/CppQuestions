#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    // Write your code here
    vector<int> ans ;
    sort(a.begin(), a.end()) ;

    int count = k ;
    for(int i = n - 1 ; i >= 0 && k != 0 ; i--, k--){
        ans.push_back(a[i]) ;
    }
    
    sort(ans.begin(), ans.end()) ;
    return ans ;
}