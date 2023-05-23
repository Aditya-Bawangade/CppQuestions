
int Solution::lis(const vector<int> &A) {
    vector<int> ans ;
    ans.push_back(A[0]) ;
    for(int i = 1 ; i < A.size() ; i++){
        if(A[i] > ans[ans.size() - 1]){
            ans.push_back(A[i]) ;
        }else{
            auto it = lower_bound(ans.begin(), ans.end(), A[i]) ;
            int idx = distance(ans.begin(), it) ;
            ans[idx] = A[i] ; 
        }
    }
    return ans.size() ;
}
