class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj ;
        for(int i = 0 ; i < pairs.size() ; i++){
            adj[pairs[i][0]].insert(pairs[i][1]) ;
            adj[pairs[i][1]].insert(pairs[i][0]) ;  
        }
        // Nodes are ordered by degree where degree implies the number of
        // times a vertex v appears in the pairs list

        // Max heap == pq
        priority_queue<pair<int,int>> pq ;
        for(auto &[node, neighbors] : adj){
            pq.push({neighbors.size(), node}) ;
        }
        int totalnodes = pq.size() ;
        int result = 1 ; 

        unordered_set<int> visited ;

        while(!pq.empty()){
            int currNode = pq.top().second ;
            int degree = pq.top().first ;

            pq.pop() ;
            
            int parent = -1 ;
            int parentdegree = INT_MAX ;

            for(auto &neighbor : adj[currNode]){
                if(visited.count(neighbor) && adj[neighbor].size() < parentdegree && adj[neighbor].size() >= degree){
                    parent = neighbor ;
                    parentdegree = adj[neighbor].size() ;
                }
            }
            visited.insert(currNode) ;
            // Checking if the currnode is the root itself 
            if(parent == -1){
                if(degree != totalnodes - 1) return 0 ;
                continue ;
            }

            for(auto &neighbor : adj[currNode]){
                if(neighbor == parent) continue ;

                if(!adj[parent].count(neighbor)) return 0 ; 
            }
            
            if(degree == parentdegree) result = 2 ;
        }
        return result ;
    }
};