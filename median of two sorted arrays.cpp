class Solution {
public:
    double util(vector<int>& nums1, vector<int>& nums2){

        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return util(nums2,nums1);
        }
        int start = 0;
        int end = m;

        while(start<=end){
            int partitionX = start + (end-start)/2;
            int partitionY = (m + n + 1)/2 - partitionX;
            int maxleftX = (partitionX == 0) ?INT_MIN:nums1[partitionX - 1];
            int maxleftY = (partitionY == 0) ?INT_MIN:nums2[partitionY - 1];
            int minrightX = (partitionX == m) ?INT_MAX:nums1[partitionX];
            int minrightY =  (partitionY == n) ?INT_MAX:nums2[partitionY];

            if(maxleftX <= minrightY && maxleftY <= minrightX){
                if((m + n)%2 == 0){
                    return double(max(maxleftX, maxleftY) + min(minrightX, minrightY))/2;
                }
                else{
                    return double(max(maxleftX,maxleftY));
                }
            }
            else if(maxleftX>minrightY){
                end = partitionX -1 ;

            }
            else{
                start = partitionX + 1;
            }
           
        }
        
         return -1.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans ;
        ans = util(nums1,nums2);
        return ans;
    }
};