#include <bits/stdc++.h>
int util(vector<int> &arr, int n){
    sort(arr.begin(), arr.end()) ;
    arr.erase(unique(arr.begin(), arr.end()), arr.end()) ; //TO remove dupli
    int ans = 1 ;
    int maxi = 1 ;
    for(int i = 1 ; i < arr.size() ; i++){
        if(arr[i] - arr[i-1] == 1){
            ans++ ;
            maxi = max(ans, maxi) ;
        }else{
            ans = 1 ;
        }
    }
    return maxi ;
}
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    return util(arr, n) ;
}
// More efficient on paper ?
// #include <bits/stdc++.h>
// int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
//     unordered_set<int> set(arr.begin(), arr.end()) ;
//     int ans = 1 ;
//     for(int i = 0 ; i < arr.size() ; i++){
//         // if(set.find(arr[i]) == set.end()){
//         //     continue ;
//         // }
//         int prev = arr[i] - 1 ;
//         int next = arr[i] + 1 ;
//         set.erase(arr[i]) ;
//         while(set.find(prev) != set.end()){
//             set.erase(prev) ;
//             prev-- ;
//         }
//         while(set.find(next) != set.end()){
//             set.erase(next) ;
//             next++ ;
//         }
//         ans = max(ans, next - prev - 1) ;
//     }
//     return ans ;
// }