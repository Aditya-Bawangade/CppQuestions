
// Optimal Binary Search O(MlogN)

bool binary(vector<vector<int>> &mat, int target, int r){
    int low = 0 ;
    int high = mat[r].size() - 1 ;

    int mid = low + (high - low)/2 ;

    while(low <= high){
        if(mat[r][mid] == target) return true ;
        else if(mat[r][mid] > target){
            high = mid - 1 ;
        }else{
            low = mid + 1 ;
        }
        mid = low + (high - low)/2 ;
    }
    return false ;
}
bool util(vector<vector<int>> &mat, int target){
    int row = mat.size() ;
    int col = mat[0].size() ;
    
    int r = 0 ; 
    int c = 0 ;
    while(r < row){
        if(target >= mat[r][0] && target <= mat[r][col - 1]){
            return binary(mat, target, r) ;
        }
        r++ ;
    }
    return false ;
}
bool searchMatrix(vector<vector<int>>& mat, int target) {
    return util(mat, target) ;
}