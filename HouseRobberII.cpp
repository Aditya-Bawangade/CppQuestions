class Solution {
public:
    int utility(vector<int>& nums, int i, int memo[]){
        if(i>nums.size()-1||nums.size()==0){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        return memo[i] = max(nums[i]+utility(nums,i+2,memo),utility(nums,i+1,memo));
    }
    int rob(vector<int>& nums, int i = 0, int j =0) {
        if(nums.size() == 1){
            return nums[0];
        }
        int memoi[nums.size()];
        for(int ia = 0; ia < nums.size(); ia++){
            memoi[ia] = -1;
        }
        int memoi2[nums.size()];
        for(int ia = 0; ia < nums.size(); ia++){
            memoi2[ia] = -1;
        }
        vector<int> nums1(nums.size()-1);
        vector<int> nums2(nums.size()-1);
        for(int i = 0 ; i < nums.size()-1 ; i++){
            nums1[i] = nums[i];
        }
        for(int i = 0 ; i < nums.size()-1 ; i++){
            nums2[i] = nums[i+1];
        }
        return max(utility(nums1,i,memoi), utility(nums2,j,memoi2));
    }
};