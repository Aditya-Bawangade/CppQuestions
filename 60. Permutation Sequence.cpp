class Solution {
public:
    int factorial(int n){
        if(n == 0 || n == 1){
            return 1 ;
        }
        return n*factorial(n-1) ;
    }
    string getPermutation(int n, int k) {
        vector<int> vis(n + 1, 0) ;
        string ans = "" ;
        int num = n ;
        // int K = k ;
        int count = 1 ;
        while(k > 1){
            for(int i = 1 ; i < n+1 ; i++){
                if(vis[i] != -1){
                    count = i ;
                    break ;
                }
            }
            int fact = factorial(num - 1) ;
            while(k > fact){
                k -= fact ;
                count += 1 ;
                while(vis[count] == -1){
                    count++ ;
                }
            }
            ans += to_string(count) ;
            vis[count] = -1 ;
            num-- ;
        }
        for(int i = 1 ; i < n + 1 ; i++){
            if(vis[i] != -1){
                ans += to_string(i) ;
            }
        }
        return ans ;
    }
};