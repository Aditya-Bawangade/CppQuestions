class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0 ; 
        int num = height.size();

        vector<int> left(num,0);
        vector<int> right(num,0);
        
        left[0] = height[0];
        right[num - 1] = height[num - 1];
        for(int i = 1 ; i < num ; i++){
            left[i] = max(left[i-1], height[i]);
        }
        for(int i = num - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i]);
        }
        for(int i = 0 ; i < num ; i++){
            // int leftmax = 0 ;
            // int rightmax = 0 ;
           

            ans += min(left[i],right[i]) - height[i];
            // for(int j = 0 ; j <= i ; j++){
            //     leftmax = max(leftmax, height[j]) ;
            // }
            // for(int j = i  ; j < num ; j++){
            //     rightmax = max(rightmax, height[j]) ; 
            // }
            // ans += min(leftmax, rightmax) - height[i];
        }
        return ans;
    }
};