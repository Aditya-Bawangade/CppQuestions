class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0; 
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(i!=0 && j!=0 && matrix[i][j] ==1){
                    int a = min(matrix[i-1][j],matrix[i][j-1]);
                    int b = min (a, matrix[i-1][j-1]);
                    matrix[i][j] = 1 + b;
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};