#include<numeric>

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int asum = accumulate(A.begin(),A.end(),0) ;
    int bsum = accumulate(B.begin(),B.end(),0) ;
    
    if(bsum > asum){
        return -1 ;
    }
    int index = 0 ; int tank = 0 ;
    for(int i = 0 ; i < A.size() ; i++){
        tank += A[i] - B[i] ;
        if(tank < 0){
            index = i + 1 ;
            tank = 0 ;
        }
    }
    return index ;
}
