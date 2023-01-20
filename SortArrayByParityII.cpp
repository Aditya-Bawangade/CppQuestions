class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> eve;
        vector<int> odd;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]%2==0){
                eve.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        for(int i = 0; i<nums.size();i++){
            if(i%2==0){
                nums[i] = eve[eve.size()-1];
                eve.pop_back();
            }
            else{
                nums[i] = odd[odd.size()-1];
                odd.pop_back();
            }
        }
        return nums;
    }
};