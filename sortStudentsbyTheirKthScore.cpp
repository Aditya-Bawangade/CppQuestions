class Solution {
public:
//   void sort(map<string, int>& M)
// {
 
//     // Declare a multimap
//     multimap<int, string> MM;
 
//     // Insert every (key-value) pairs from
//     // map M to multimap MM as (value-key)
//     // pairs
//     for (auto& it : M) {
//         MM.insert({ it.second, it.first });
//     }
 
//     // Print the multimap
//     // for (auto& it : MM) {
//     //     cout << it.second << ' ' << it.first << endl;
//     // }
// }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        map<int,int,greater<int>> mp;
        for(int i = 0 ; i < score.size(); i++){
            mp[score[i][k]]+=i;
        }
        
        // for(auto x:mp){
        //     cout<<x.first<<x.second<<endl;
        // }
        vector<int> arr;
        for(auto x:mp){
            arr.push_back(x.second);
        }
        
        // sort(arr.begin(),arr.end(),greater<>());
        // vector<int> indexes;
        // for(int i = 0 ; i< score.size(); i++){
        //     indexes.push_back()
        // }
        for(int i = 0; i<score.size();i++){
            ans.push_back(score[arr[i]]);
        }
        return ans;
    }
};