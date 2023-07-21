#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    // vector<int> ans ;
    int count = 0 ;
    int i = 0 ;
    int j = 0 ;
    bool left = false ;
    bool right = false ;
    while(i < n && j < m){
        if(count == k){
            if(left){
                // cout<<"one" ;
                return arr1[i - 1] ;
            }else if (right){
                // cout<<"two" ;
                return arr2[j - 1] ; 
            }
        }
        if(arr1[i] < arr2[j]){
            i++ ;
            left = true ;
            right = false ;
            count++ ;
        }else{
            j++ ;
            right = true ; 
            left = false ;
            count++;
        }
    }
    if(count == k){
        if(left){
            return arr1[n - 1] ;
        }else{
            return arr2[m - 1] ;
        }
    }
    while(i < n){
        if(count == k){
            // cout<<"three" ;

            return arr1[i - 1] ;
        }
        count++ ;
        i++ ;
        
    }
    while(j < m){
        if(count == k){
            // cout<<"four" ;
            return arr2[j - 1] ;
        }
        count++ ;
        j++ ;
        
    }
    return 0 ;
    // for(int i = 0 ; i < n ; i++){
    //     ans.push_back(arr1[i]) ;
    // }
    // for(int i = 0 ; i < m ; i++){
    //     ans.push_back(arr2[i]) ;
    // }
    // sort(ans.begin(), ans.end()) ;
    // return ans[k - 1] ;
}