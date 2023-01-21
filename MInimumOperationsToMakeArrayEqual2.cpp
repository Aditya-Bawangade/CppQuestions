class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long posi = 0;
        long long nega = 0;
        if(k==0){
            if(nums1!=nums2){
                return -1;
            }
            return 0;
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            int diff = nums1[i]-nums2[i];
            if(diff%k != 0){
                return -1;
            }
            if(nums1[i] > nums2[i]){
                nega += abs(diff)/k;
            }
            if(nums1[i] < nums2[i]){
                posi += abs(diff)/k;
            }
        }
        if(posi == nega){
            return posi;
        }
        return -1;
    }
};