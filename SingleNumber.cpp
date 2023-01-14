class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = nums.size();
        int ans = -1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < s ;i+=2){
            if(i == s-1){
               return nums[i];
            }
            else if(nums[i] != nums[i+1]){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};