class Solution {
    int dp[366];
    int solve(vector<int>& days, vector<int>& costs, int i, int x){
        if(x<=0) return 0;

        if(dp[x] != -1)
           return dp[x];

        int cnt1=INT_MAX-1; int cnt2=INT_MAX-1; int cnt3=INT_MAX-1;

        while(i>=0 && x<days[i]){
            i--;
        } if(i<0) return 0;
       
        cnt1=costs[0]+solve(days, costs, i, days[i]-1);
        cnt2=costs[1]+solve(days, costs, i, days[i]-7);
        cnt3=costs[2]+solve(days, costs, i, days[i]-30);

       return dp[x]=min(cnt1, min(cnt2, cnt3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, days.size()-1, days[days.size()-1]);
    }
};