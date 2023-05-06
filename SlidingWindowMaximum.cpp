class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans ;
        // int i = 0 ;
        // int j =  k - 1 ;

        // while( j < nums.size()){
        //     int maxE = *max_element(nums.begin() + i , nums.begin() + j + 1) ;
        //     ans.push_back(maxE) ; 
        //     i++;
        //     j++;
        // }
        // return ans ;
        multiset<int> MS ; 
        
        for(int i = 0 ; i < nums.size() ; i++){
          if(i >= k){
            ans.push_back(*MS.rbegin()) ;
          }
          if(i >= k){
            MS.erase(MS.find(nums[i-k])) ;
          }
          MS.insert(nums[i]) ;
         
          
        }
        ans.push_back(*MS.rbegin()) ;

      return ans ;
    }
};