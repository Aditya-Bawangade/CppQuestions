	// int splitArray(vector<int>& nums, int m) {
    //     int l=0,r=0,n=nums.size();
    //     for(int i=0;i<n;++i) l=max(l,nums[i]), r+=nums[i];
        
    //     int mid=0,ans=0;
    //     while(l<=r){
    //         mid=(l+r)/2;
    //         int count=0,tempsum=0;
    //         for(int i=0;i<n;++i){
    //             if(tempsum+nums[i]<=mid) tempsum+=nums[i];
    //             else count++,tempsum=nums[i];
    //         }
    //         count++; 
            
    //         if(count<=m) r=mid-1, ans=mid;
    //         else l=mid+1;
    //     }  
    //     return ans;
    // }
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0 ;
        int right = 0 ;
        int n = nums.size() ;
        left = *max_element(nums.begin(),nums.end()) ;
        right = accumulate(nums.begin()+0,nums.end(),0) ;
        // cout<<left<<" "<<right<<endl ;
        int mid = 0 ; int ans = 0 ;

        while(left <= right){
            mid = (left + right)/2 ;
            int count = 0 ; int temp = 0 ;
            for(int i = 0 ; i < n ; i++){
                if(temp + nums[i] <= mid){
                    temp += nums[i];
                }
                else{
                    count++;
                    temp = nums[i] ;
                }
                
            }
            count++ ;
            if(count <= k){
                right = mid - 1 ;
                ans = mid ;
            }
            else{
                left = mid + 1;
            }
        }
        return ans ;
    }
};