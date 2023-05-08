class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0 ; 
        for(int i = n/2 - 1 ; i >= 0 ; i--){
            int leftchild = 2*i + 1 ;
            int rightchild = 2*i + 2 ;
            ans += abs(cost[leftchild] - cost[rightchild]) ;
            cost[i] += max(cost[leftchild],cost[rightchild]) ; 
        }
        return ans ;
    }
};