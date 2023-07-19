#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> stk ;
    stk.push(-1) ;
    vector<int> ans(n) ;
    
    for(int i = n - 1 ; i >= 0 ; i--){
        int curr = arr[i] ;
        while(stk.top() >= curr){
            stk.pop() ;
        }
        ans[i] = stk.top() ;
        stk.push(curr) ;
    }
    return ans ;
}