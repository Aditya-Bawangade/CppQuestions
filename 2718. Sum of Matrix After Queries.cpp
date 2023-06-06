class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0, cols = n, rows = n ;
        vector<bool> col(n), row(n) ;

        for(int i = queries.size() - 1 ; i >= 0 ; i--){
            if(queries[i][0] == 0){
                if(!row[queries[i][1]]){
                    row[queries[i][1]] = true ;
                    --rows ;
                    ans += cols*queries[i][2] ;
                }
            }
            else{
                if(!col[queries[i][1]]){
                    col[queries[i][1]] = true ;
                    --cols ;
                    ans += rows*queries[i][2] ;
                }
            }
        }
        return ans ;
    }
};