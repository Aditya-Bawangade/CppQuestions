class Solution {
    vector<int> uniq ;
    unordered_map<int,int> mp ;
public:
    int partition(int left, int right, int pvtidx){
        int pvtfreq = mp[uniq[pvtidx]] ;
        swap(uniq[pvtidx], uniq[right]) ;
        int storeidx = left ;
        for(int i = left ; i <= right; i++){
            if(mp[uniq[i]] < pvtfreq){
                swap(uniq[storeidx], uniq[i]) ;
                storeidx += 1 ;
            }
        }
        swap(uniq[right], uniq[storeidx]) ;
        return storeidx ;
    }
    void util(int left, int right, int ksmall){
        if(left == right){
            return ;
        }
        int pvtidx = left + rand()%(right - left + 1) ;
        pvtidx = partition(left, right, pvtidx) ;
        if(ksmall == pvtidx){
            return ;
        }else if(ksmall < pvtidx){
            util(left, pvtidx - 1, ksmall) ;
        }else{
            util(pvtidx + 1, right, ksmall) ;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] += 1 ;
        }
       
        for(auto it : mp){
            uniq.push_back(it.first) ;
        }
        int n = mp.size() ;
        util(0, n-1, n-k) ;
        vector<int> ans(k) ;
        copy(uniq.begin() + n - k, uniq.end(), ans.begin()) ;
        return ans ;
    }
};