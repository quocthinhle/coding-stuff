public class Leet37_SodokuSolver {
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    
    private boolean solve(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private boolean isValid(char[][] board, int row, int col, char c){
        for (int count = 0; count < 9; ++count) {
            if (board[row][count] != '.' && board[row][count] == c) return false;
            if (board[count][col] != '.' && board[count][col] == c) return false;
        }
        
        int offsetX = ((int)(row/3))*3;
        int offsetY = ((int)(col/3))*3;
        
        for (int m = offsetX; m < offsetX + 3; ++m) {
            for (int n = offsetY; n < offsetY + 3; ++n) {
                if (m == row && n == col) continue;
                else {
                    if (board[m][n] != '.' && board[m][n] == c) return false;
                }
            }
        }
        
        return true;
    }
}