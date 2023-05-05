class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans ;

        multiset<int> pq{0} ;

        // storing the individual points in a vector of pairs to distinguish as starting and ending

        vector<pair<int,int>> v ;
        for(auto p : buildings){
            v.push_back({p[0], -1*p[2]}) ;
            v.push_back({p[1], p[2]}) ;
        }

        sort(v.begin(), v.end()) ;

        int ongoingH = 0 ;

        for(auto i : v){
            int currPoint = i.first ; 
            int currHeight = i.second ;
            if(currHeight < 0){
                pq.insert(-currHeight) ;
            }
            else{
                pq.erase(pq.find(currHeight)) ;
            }
            auto pqtop = *pq.rbegin() ; 
            if(ongoingH != pqtop){
                ongoingH = pqtop ;
                ans.push_back({currPoint, ongoingH});
            }
        }
        return ans ;
    }
};