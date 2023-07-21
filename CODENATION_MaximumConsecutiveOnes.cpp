int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int left = 0 ; 
    int right = 0 ;
    int ans = 0 ;
    while(right < n){
        if(arr[right] == 1){
            right++ ;
            continue ;
        }
        if(k > 0){
            k-- ;
            right++ ;
        }else{
            ans = max(ans, right - left) ;
            while(left <= right && k == 0){
                if(arr[left] == 0){
                    k++ ;
                }
                left++ ;
            }
        }
    }
    ans = max(ans, right - left) ;
    return ans ;
}
