class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
       vector<int> degrees(n+1,0); 
       map<pair<int,int>,bool> mp;
       for(int i = 0 ; i < edges.size() ; i++){
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
            mp[{edges[i][0],edges[i][1]}] = 1 ;
            mp[{edges[i][1],edges[i][0]}] = 1 ;
       } 
       vector<int> odds; 
       for(int i = 0 ; i < n+1 ; i++){
           if(degrees[i]%2 != 0){
               odds.push_back(i) ;
           }
       }
       if(odds.size() == 0){
           return true ;
       }
       if(odds.size() > 4 || odds.size() == 1 || odds.size() == 3){
          return false ;
       }
       if(odds.size() == 2){
           int a = odds[0]; 
           int b = odds[1];
           if(mp[{a,b}]){
               for(int i = 1 ; i <= n ; i++){
               if(i == a || i == b) continue ;
               if(!mp[{a,i}] && !mp[{b,i}]){
                   return true ;
               }
           }
           return false ;
        }
        return true ;   
       }
       if(odds.size() == 4){
           int a = odds[0] ; 
           int b = odds[1] ;
           int c = odds[2] ;
           int d = odds[3] ;
           if(!mp[{a,b}] && !mp[{c,d}]) return true ;
           if(!mp[{a,c}] && !mp[{b,d}]) return true ;
           if(!mp[{a,d}] && !mp[{c,b}]) return true ;
           return false ;
        }
        return false ;
    }
};