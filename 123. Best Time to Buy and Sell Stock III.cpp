class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> leftProfit(prices.size()) ;
        vector<int> rightProfit(prices.size()) ;

        int n = prices.size() ;
        leftProfit[0] = 0 ;
        rightProfit[n-1] = 0 ;
        int leftmin = prices[0] ;
        int rightmax = prices[n-1] ;
        int i ;
        int j ;

        for(int i = 1, j = n - 2 ; i < n && j >= 0 ; i++, j--){
            leftmin = min(leftmin, prices[i]) ;
            leftProfit[i] = max(leftProfit[i-1], prices[i] - leftmin) ; 

            rightmax = max(rightmax, prices[j]) ;
            rightProfit[j] = max(rightProfit[j+1], rightmax - prices[j]) ; 
        }

        int ans = 0 ;

        for(int i = 0 ; i < prices.size() ; i++){
            ans = max(ans, leftProfit[i] + rightProfit[i]) ;
        }
        
        return ans ;
    }
};