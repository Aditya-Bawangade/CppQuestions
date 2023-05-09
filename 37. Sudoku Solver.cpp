class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int i, int j, char ch){
        for(int ii = 0 ; ii  < 9 ; ii++){
            if(board[i][ii] == ch){
                return false ;
            }
            if(board[ii][j] == ch){
                return false ;
            }
            if(board[3*(i/3) + (ii/3)][3*(j/3) + (ii%3)] == ch){
                return false ;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j] = c ;
                            if(solve(board)){
                                return true ;
                            }
                            else{
                                board[i][j] = '.' ;
                            }
                        }
                    }
                    return false ;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};