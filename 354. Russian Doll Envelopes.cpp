class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0] ; 
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size() ;
        if(n == 0){
            return 0 ;
        }
        sort(envelopes.begin(),envelopes.end(),comparator) ;
        vector<int> dp ;
        int ans = 1 ;
        for(auto i : envelopes){
            auto it = lower_bound(dp.begin(),dp.end(),i[1]) ;
            if(it == dp.end()){
                dp.push_back(i[1]) ;
            }
            else{
                *it = i[1] ;
            }
        }
        return dp.size() ;
    }
};