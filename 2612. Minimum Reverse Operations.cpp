class Solution {
public:
    pair<int,int> Range(int p, int n, int k){
        int l = max(0, p - k + 1) ;
        int r = min(n - k, p) ;

        int L = 2*l + k - 1 - p ;
        int R = 2*r + k - 1 - p ;

        return {L, R} ; 
    }
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        set<int> E[2] ;
        for(int i = 0 ; i < n ; i++){
            E[i & 1].insert(i) ;
        }
        // for(int i = 0; i < n; i++) E[i & 1].insert(i);
        
        int B = (int)banned.size() ;

        for(int i = 0 ; i < B ; i++){
            E[banned[i] & 1].erase(banned[i]) ;
        }
        // for(int i = 0; i < B; i++) E[banned[i] & 1].erase(banned[i]);

        vector<int> ans(n,-1) ;
        queue<int> q ;
        q.push(p) ;

        ans[p] = 0 ;

        E[p & 1].erase(p) ;

        while(!q.empty()){
            int x = q.front() ;
            q.pop() ;

            pair<int,int> P = Range(x,n,k) ;

            set<int>& curr = E[P.first & 1] ; 
            auto it = curr.lower_bound(P.first) ;

            while(it != curr.end() && *it <= P.second){
                ans[*it] = ans[x] + 1 ;
                q.push(*it) ;
                it = curr.erase(it) ;
            }
        }
        return ans ;
        // unordered_set<int> B(banned.begin(), banned.end()) ;

        // vector<int> ans(n, -1) ;
        // queue<int> Q ;
        // Q.push(p) ;
        // ans[p] = 0 ;
        
        // while(!Q.empty()){
        //     int top = Q.front() ;
        //     Q.pop() ;
        //     pair<int,int> P = Range(top,n,k) ;
        //     for(int i = P.first ; i <= P.second ; i += 2){
        //         if(ans[i] != -1 || B.count(i)){
        //             continue ;
        //         }
        //         ans[i] = ans[top] + 1 ;
        //         Q.push(i) ;
        //     }
        // }
        // return ans ;

    }
};