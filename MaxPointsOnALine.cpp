class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i = 0 ; i < points.size() ; i++){
            int samepoint = 1 ;
            vector<int> ans = points[i];
            unordered_map<double,int> mp;
            for(int j = i+1 ; j < points.size() ; j++){
                double slope ;
                if(points[j][0] == ans[0] && points[j][1] == ans[1]){
                    samepoint++;
                    continue;
                }
                if(ans[0] - points[j][0] == 0){
                    slope = INT_MAX ; 
                }
                else{
                    slope = double(ans[1] - points[j][1])/double(ans[0] - points[j][0]) ;
                }
                mp[slope]++;
            }
            int max_freq = 0;
        
            for (const auto& kv : mp) {
                if (kv.second > max_freq) {
                    max_freq = kv.second;
                }
            }
            result = max(result,max_freq + samepoint);

        }
        
        return result ;
    }
};              