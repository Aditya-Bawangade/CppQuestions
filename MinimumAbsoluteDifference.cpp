class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minsum = arr[1] - arr[0];
        vector<vector<int>> answer;
        vector<int> ans = {arr[0], arr[1]};
        answer.push_back(ans);
        for(int i = 1 ; i < arr.size()-1; i++){
            vector<int> a;
            if(arr[i+1] - arr[i] < minsum){
                answer.clear();
                minsum = arr[i+1] - arr[i];
                a.push_back(arr[i]);
                a.push_back(arr[i+1]);
            }
            else if(arr[i+1] - arr[i] == minsum){
                a.push_back(arr[i]);
                a.push_back(arr[i+1]);
            }
            if(!a.empty()){
                answer.push_back(a);
            }
            
        }
        return answer;
    }
};