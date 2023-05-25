int Solution::maxProfit(const vector<int> &nums) {
    int profit = 0 ;
    if(nums.size() == 0) return profit ;
    for(int i = 0 ; i < nums.size() - 1 ; i++){
        if(nums[i] < nums[i + 1]) profit += nums[i+1] - nums[i] ;
    }
    return profit ;
}
