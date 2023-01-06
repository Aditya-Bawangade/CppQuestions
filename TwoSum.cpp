#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        bool flag = 0;
        for(i;i<nums.size();i++){
            for(j = i+1;j<nums.size();j++){
                if( nums[j] == (target- nums[i])){
                    flag = 1;
                    break;
                }

            }
            if(flag){
                break;
            }
        }
        vector<int> ans = {i,j};
        return ans;
    }
};