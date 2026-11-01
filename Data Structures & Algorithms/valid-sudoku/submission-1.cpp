class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (auto i = 0; i < 9; i++) {
            bool row_check[9] = {};
            bool col_check[9] = {};
            bool box_check[9] = {};
            for (auto j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = (board[i][j]) - '1';
                    if (row_check[val]) return false;
                    row_check[val] = true;
                }
                if (board[j][i] != '.') {
                    int val = board[j][i] - '1';
                    if (col_check[val]) return false;
                    col_check[val] = true;
                }
                auto box_i = (i / 3) * 3 + (j % 3);
                auto box_j = (i % 3) * 3 + j / 3;

                if (board[box_i][box_j] != '.') {
                    int val = (board[box_i][box_j]) - '1';
                    if (box_check[val]) return false;
                    box_check[val] = true;
                }
            }
        }
        return true;
    }
};
