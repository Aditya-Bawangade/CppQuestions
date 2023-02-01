class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
      }  
      if(sum%2 != 0){
          return false;
      }
      int s = sum/2;
      unordered_set<int> dp = {0};
      for(int i = 0 ; i < nums.size() ; i++){
          unordered_set<int> dpnext;
          for(auto  j = dp.begin() ; j != dp.end() ; j++){
              if(*j + nums[i] == s){
                  return true;
              }
              dpnext.insert(*j);
              dpnext.insert(*j+nums[i]);
          }
          dp = dpnext;
      }
      return false;
    }
};