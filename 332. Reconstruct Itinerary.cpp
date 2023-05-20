class Solution {
public:
    map<string, multiset<string>> targets ;
    vector<string> ans ;
    void visit(string airport){
        while(targets[airport].size()){
            string next = *targets[airport].begin() ;
            targets[airport].erase(targets[airport].begin()) ;
            visit(next) ;
        }
        ans.push_back(airport) ;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            targets[ticket[0]].insert(ticket[1]) ;
        }
        visit("JFK") ;
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};