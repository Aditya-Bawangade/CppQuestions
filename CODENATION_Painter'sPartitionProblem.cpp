bool isvalid(vector<int> &boards, int k, int maxlim){
    int ptrcnt = 1 ; 
    int brdcnt = 0 ;

    for(int i = 0 ; i < boards.size() ; i++){
        if(boards[i] + brdcnt <= maxlim){
            brdcnt += boards[i] ;
        }else{
            ptrcnt += 1 ;
            if(ptrcnt > k || boards[i] > maxlim){
                return false ;
            }
            brdcnt = boards[i] ;
        }
    }
    return true ;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = 0 ;
    int high = accumulate(boards.begin(), boards.end(), 0) ;
    int ans = -1 ;
    int mid = low + (high - low)/2 ;
    while(low <= high){
        if(isvalid(boards, k, mid)){
            ans = mid ;
            high = mid - 1 ;
        }else{
            low = mid + 1 ;
        }
        mid = low + (high - low)/2 ;
    }
    return ans ;
}