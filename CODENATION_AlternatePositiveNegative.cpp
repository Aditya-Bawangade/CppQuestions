#include <bits/stdc++.h> 

void posAndNeg(vector<int> &arr)
{
   int pos = 0 ;
   int neg = 1 ;
   vector<int> util ;
   for(int i = 0 ; i < arr.size() ; i++){
       util.push_back(arr[i]) ;
   } 
   int ptr = 0 ;
   while(ptr < util.size()){
       if(util[ptr] >= 0){
           arr[pos] = util[ptr] ;
           ptr++ ;
           pos += 2 ;
       }
       if(util[ptr] < 0){
           arr[neg] = util[ptr] ;
           ptr++ ;
           neg += 2 ;
       }
    // ptr++ ;
   }
    return ;
}