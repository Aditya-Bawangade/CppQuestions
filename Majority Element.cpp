int Solution::majorityElement(const vector<int> &A) {
    if(A.size() == 1){
        return A[0] ;
    }
    unordered_map<int,int> mp ;
    for(int i = 0 ; i < A.size() ; i++){
        mp[A[i]] += 1;
    }
    for(const auto& pair: mp){
        if(pair.second > floor(A.size()/2)){
            return pair.first ;
        }
    }
    return -1 ;
}
