class UnionFind{
    vector<int> parent ;
    int distinct ;
public:
    UnionFind(int n){
        distinct = n ;
        for(int i = 0 ; i <= n ; i++){
            parent.push_back(i) ;
        }
    }
    
    bool combine(int a, int b){
        if(find(a) == find(b)){
            return false ;
        }
        parent[find(a)] =  b ;
        distinct-- ;
        // cout<<distinct<<endl ;
        return true ;
    }
    int find(int a){
        if(parent[a] != a){
            parent[a] = find(parent[a]) ;
        }
        return parent[a] ;
    }
    bool united(){
        return distinct == 1 ;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b){return a[0] > b[0] ; } );  
        int added = 0 ;
        UnionFind Bob(n), Alice(n) ;
        for(auto &it : edges){
            // cout<<"for loop"<<endl ;
            int type = it[0], u = it[1], v = it[2] ;
            switch(type){
                case 3:
                    // cout<<"case3"<<endl ;
                    added += (Bob.combine(u, v) | Alice.combine(u, v)) ;
                    // break ;
                    // cout<<added<<endl ;
                    break ;
                case 2: 
                    // cout<<"case2"<<endl ;
                    added += Bob.combine(u, v) ;
                    break ;
                case 1: 
                    // cout<<"case1"<<endl ;
                    added += Alice.combine(u, v) ;
                    break ;
            }
        } 
        return (Bob.united() && Alice.united()) ? (edges.size() - added) : -1 ;    
    } 
};