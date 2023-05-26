class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vec ;
        for(int i = 0 ; i < profits.size() ; i++){
            vec.push_back({capital[i],profits[i]}) ;
        }
        sort(vec.begin(),vec.end()) ;

        priority_queue<int> q ;
        int ptr = 0 ;
        for(int i = 0 ; i < k ; i++){
            while(ptr < profits.size() && vec[ptr].first <= w){
                q.push(vec[ptr].second) ;
                ptr++ ;
            }
            if(q.empty()) break ;
            w += q.top() ;
            q.pop() ;
        }
        return w ;

    }
};