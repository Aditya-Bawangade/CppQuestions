class Solution {
public:
    void merge(vector<pair<int,int>> &nums, int start, int mid, int end, vector<int> &ans){
        vector<pair<int,int>> finans(end-start+1) ;
        int i = start ;
        int j = mid + 1 ;
        int k = 0 ;
        int SOR = 0 ;
        while(i <= mid && j <= end){
            if(nums[i].first <= nums[j].first){
                ans[nums[i].second] += SOR ;
                finans[k] = nums[i] ;

                i++; 
                k++;
            }
            else{
                SOR++ ;
                finans[k] = nums[j] ;
                j++ ; 
                k++ ;
            }
        }
        while(i <= mid){
            ans[nums[i].second] += SOR ;
            finans[k] = nums[i] ;
            i++; 
            k++;
        }
        while(j <= end){
            finans[k] = nums[j] ;
            j++ ; 
            k++ ;
        }
        i = start ;
        k = 0 ; 
        while(i <= end){
            nums[i] = finans[k] ;
            i++ ;
            k++ ;
        }
    }
    void mergesort(vector<pair<int,int>> &nums, int start, int end, vector<int> &ans){
        if(start >= end){
            return ;
        }
        int mid = start + (end - start)/2 ;
        mergesort(nums, start, mid, ans) ;
        mergesort(nums, mid+1, end, ans) ;

        merge(nums, start, mid, end, ans) ;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> JK(nums.size()) ;
        for(int i = 0 ; i < nums.size() ; i++){
            JK[i] = {nums[i], i} ;
        }
        vector<int> ans(nums.size(), 0) ;
        mergesort(JK, 0, nums.size() - 1, ans) ;

        return ans ;
    }
};