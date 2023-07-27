vector<int> countPrimes(int n)
{
    vector<int> ans ;
    while(n%2 == 0){
        ans.push_back(2) ;
        n = n/2 ;
    }
    for(int i = 3 ; i <= sqrt(n) ; i += 2){
        while(n % i == 0){
            ans.push_back(i) ;
            n = n/i ;
        }
    }

    if(n > 2){
        ans.push_back(n) ;
    }
    unordered_set<int> st ;
    for(int i = 0 ; i < ans.size() ; i++){
        st.insert(ans[i]) ;
    }

    vector<int> res ; 
    for(auto i : st){
        res.push_back(i) ;
    }
    sort(res.begin(), res.end()) ;
    return res ;
}