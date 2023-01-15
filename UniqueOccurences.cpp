class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int s = arr.size();
        for(int i = 0 ; i <s ; i++){
            mp[arr[i]]++;
        }
        vector<int> values(s, -1);
        bool flag = 1;
        for(auto x : mp){
            if(values[x.second - 1] == 1){
                flag = 0;
                break;
            }
            values[x.second - 1] = 1;
        }
        return flag;
    }
};