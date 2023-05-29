class TreeAncestor {
public:
    vector<vector<int>> ancestors ; //ancestors[i][node]::: node's 2^ith parent
    TreeAncestor(int n, vector<int>& parent) {
        ancestors.resize(20, vector<int>(n,-1)) ;
        for(int i = 0 ; i < parent.size() ; i++){
            ancestors[0][i] = parent[i] ; 
        }
        for(int i = 1 ; i < 20 ; i++){
            for(int node = 0 ; node < parent.size() ; node++){
                int par = ancestors[i-1][node] ;
                if(par != -1){
                    ancestors[i][node] = ancestors[i-1][par] ;
                }
            }
        }
    }
    // void util(int node, int k){
        
    //     int i = node ;
    //     int lim = k ;
    //     while(i >= 0 && i < parents.size() && lim--){
    //         i = parents[i] ;
    //         if(i != -1 && ancestors[i][lim] != -1){
    //             ancestors[node][k] = ancestors[i][lim] ;
    //         }
    //     }
    //     ancestors[node][k] = i ;
    // }
    int getKthAncestor(int node, int k) {
        // if(k >= num || node >= num) return -1 ;
        // if(ancestors[node][k] != -1){
        //     return ancestors[node][k] ;
        // }
        // util(node, k) ;
        // return ancestors[node][k] ;
        for(int i = 0 ; i < 20 ; i++){
            if(k & (1<<i)){
                node = ancestors[i][node] ;
                if(node == -1) return -1 ;
            }
        }
        return node ;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */