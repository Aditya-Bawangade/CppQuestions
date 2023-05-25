class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // vector<int> ans, mono ;
        // for(int a : obstacles){
        //     int l = 0, r = mono.size() ;
        //     while(l < r){
        //         int mid = (l+r)/2 ;
        //         if(mono[mid] <= a){
        //             l = mid + 1 ; 
        //         }
        //         else{
        //             r = mid ;
        //         } 
        //     }
        //     ans.push_back(l+1) ;
        //     if(mono.size() == l){
        //         mono.push_back(a) ;
        //     }
        //     mono[l] = a ;
        // }
        // return ans ;
        vector<int> util ;
        for(int i = 0 ; i < obstacles.size() ; i++){
            int x = obstacles[i] ;
            if(util.empty() || util[util.size()-1] <= x){
                util.push_back(x) ;
                obstacles[i] = util.size() ;
            }else{
                int index = upper_bound(util.begin(), util.end()
                ,x) - util.begin() ;
                util[index] = x ;
                obstacles[i] = index + 1 ;
            }
        }
        return obstacles ;
    }
};