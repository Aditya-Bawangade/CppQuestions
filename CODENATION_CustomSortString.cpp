#include <bits/stdc++.h> 
string specificOrder(string & x, string & y) {
    string ans = "" ;
    for(int i = 0 ; i < y.length() ; i++){
        for(int j = 0 ; j < x.length() ; j++){
            if(x[j] == y[i]){
                ans += x[j] ;
            }
        }
    }
    x = ans ;

    return x ;
}