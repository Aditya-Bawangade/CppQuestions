#include<vector>
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 1;
        int size = nums.size();
        if(nums[0]>=nums[size-1]){
            for(int i = 0; i < size-1; i++){
                if(nums[i+1] > nums[i]){
                    flag = 0;
                    break;
                }
        }
        }
        else if(nums[0]<=nums[size-1]){
           for(int i = 0; i <size-1; i++){
                if(nums[i+1] < nums[i]){
                    flag = 0;
                    break;
                }
           } 
        }
        
        return flag;
    }
};