class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == weights.size() || k > weights.size()){
            return 0;
        }
        vector<long long int> ans;
        for(int i = 0 ; i < weights.size()-1; i++){
            ans.push_back(weights[i]+weights[i+1]);
        }
        sort(ans.begin(),ans.end());
        long long int minsum = 0;
        for(int i = 0 ; i <k-1 ; i++){
            minsum+= ans[i];
        }
        long long int maxsum = 0 ;  
        for(int i = ans.size()-1 ; i>= ans.size()-k+1 ; i--){
            maxsum+= ans[i];
        }
        return (maxsum - minsum);
    }
};