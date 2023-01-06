#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int> ans(nums.size());
        for(int i = 0; i<nums.size(); i++){
            int counter = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j]<nums[i]){
                    counter++;
                }
            }
            ans[i] = counter;
        }
        return ans;
    }
};