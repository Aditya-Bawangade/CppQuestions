#include<bits/stdc++.h>
long long getTrappedWater(long long* arr, int n) {
    vector<long long> leftmax(n, -1) ;
    leftmax[0] = arr[0] ;
    for(int i = 1 ; i < n ; i++){
        leftmax[i] = max(leftmax[i - 1], arr[i]) ;
    }

    vector<long long> rightmax(n, -1) ;
    rightmax[n - 1] = arr[n - 1] ;
    for(int i = n - 2 ; i >= 0 ; i--){
        rightmax[i] = max(rightmax[i + 1], arr[i]) ;
    }
    long long ans = 0 ;
    for(int i = 1 ; i < n - 1 ; i++){
        ans += min(leftmax[i], rightmax[i]) - arr[i] ;
    }
    return ans ;
}