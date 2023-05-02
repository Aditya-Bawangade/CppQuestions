class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // vector<int> util(nums.size() + 1, -1);

        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(nums[i] <= 0 || nums[i] - 1 >= nums.size()){
        //         continue;
        //     }
        //     util[nums[i]-1] = 1;
        // }
        // for(int i = 0 ; i <= util.size() ; i++){
        //     if(util[i] == -1){
        //         return i + 1;
        //     }
        // }
        // return 0;

        int num = nums.size();
        for(int i = 0 ; i < num ; i++){
            if(nums[i] <= 0){
                nums[i] = num + 1 ;

            }
        }
        for(int i = 0 ; i < num ; i++){
            if(abs(nums[i]) <= num && nums[abs(nums[i]) -1] > 0){
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for(int i = 0 ; i < num; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return num + 1;
    }

};