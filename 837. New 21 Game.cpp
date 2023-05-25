class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1.0 ;
        vector<double> p(n+1) ;
        p[0] = 1.0 ;
        double Wsum = 1.0 ;
        double ans = 0.0 ;
        for(int i = 1 ; i <= n ; i++){
            p[i] = Wsum/maxPts;
            if(i < k){
                Wsum += p[i] ;
            }else{
                ans += p[i] ;
            }
            if(i - maxPts >= 0){
                Wsum -= p[i-maxPts] ;
            } 
        }
        return ans ;
    }
};