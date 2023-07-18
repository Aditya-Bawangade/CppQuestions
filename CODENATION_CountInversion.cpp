#include <bits/stdc++.h> 
int merge(long long *arr, int low, int mid, int high){
    vector<int> trash ;
    int left = low ;
    int right = mid + 1 ;
    int ans = 0 ;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            trash.push_back(arr[left]) ;
            left++ ;
        }else{
            trash.push_back(arr[right]) ;
            ans += mid - left + 1 ; //If right++ then it is clear that there is an inversion
            right++ ;
        }
    }
    while(left <= mid){
        trash.push_back(arr[left]) ;
        left++ ;
    }
    while(right <= high){
        trash.push_back(arr[right]) ;
        right++ ;
    }
    for(int i = low ; i <= high ; i++){
        arr[i] = trash[i - low] ;
    }
    return ans ;
}
int mergesort(long long *arr, int low, int high){
    int ans = 0 ;
    if(low == high) return ans ;
    int mid = (low + high)/2 ;
    ans += mergesort(arr, low, mid) ;
    ans += mergesort(arr, mid + 1, high) ;
    ans += merge(arr, low, mid, high) ;
    return ans ;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergesort(arr, 0, n - 1) ;
    
}