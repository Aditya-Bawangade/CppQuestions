int mod = 1e9 + 7 ;
int *getProductArrayExceptSelf(int *arr, int n)
{
    //Write your code here
    
    int *trash = new int[n] ;
    if(n == 0) return trash ;
    trash[0] = 1 ;
    for(int i = 1 ; i < n ; i++){
        trash[i] = ((long long)trash[i-1]*arr[i-1]) %mod ;
    }
    long long prod = 1 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        trash[i] = (trash[i] * prod) %mod ;
        prod = (prod*arr[i]) %mod ;
        
    }
    return trash ;
}