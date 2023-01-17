class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        int count = -1;
        for(auto x : mp){
            if(x.first == x.second && x.first>=count){
                count = x.first;
            }
        }
        return count;
    }
};