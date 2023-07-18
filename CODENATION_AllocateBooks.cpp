bool isvalid(vector<int> &arr, int n, int m, int maxlim){
    int stdcount = 1 ;
    int pgsm = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(pgsm + arr[i] <= maxlim){
            pgsm += arr[i] ;
        }else{
            stdcount += 1 ;
            if(stdcount > m || arr[i] > maxlim){
                return false ;
            }
            pgsm = arr[i] ;
        }
        if(m > n){
            return false ;
        }
    }
    return true ;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    int start = 0 ;
    int sum = 0 ;

    for(int i = 0 ; i < n ; i++){
        sum += arr[i] ;
    }
    int end = sum ; 
    int ans = -1 ;
    int mid = start + (end-start)/2 ;

    while(start <= end){
        if(isvalid(arr, n, m, mid)){
            ans = mid ;
            end = mid - 1 ;
        }else{
            start = mid + 1 ;
        }
        mid = start + (end-start)/2 ;
    }
    return ans ;

}