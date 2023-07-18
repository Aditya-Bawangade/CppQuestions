#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    vector<int> leftsmall(prices.size()) ;
    leftsmall[0] = prices[0] ;

    for(int i = 1 ; i < prices.size() ; i++){
        leftsmall[i] = min(leftsmall[i-1], prices[i]) ;
    }

    vector<int> rightmax(prices.size()) ;
    rightmax[prices.size() - 1] = prices[prices.size() - 1] ;

    for(int i = prices.size() - 2 ; i >= 0 ; i--){
        rightmax[i] = max(rightmax[i+1], prices[i]) ;
    }

    int ans = 0 ; 
    for(int i = 0 ; i < prices.size() ; i++){
        ans = max(ans, rightmax[i] - leftsmall[i]) ;
    }
    
    return ans ;
}