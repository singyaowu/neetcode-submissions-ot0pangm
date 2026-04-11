class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, string &word, int b_i, int b_j, int w_i) {
        if (b_i < 0 || b_i >= board.size() || b_j < 0 || b_j >= board[0].size())
            return false;
        if (board[b_i][b_j] != word[w_i])
            return false;
        if (w_i == word.size() - 1)
            return true;

        board[b_i][b_j] = '-';
        auto ret = dfs(board, word, b_i + 1, b_j, w_i + 1) ||
                   dfs(board, word, b_i - 1, b_j, w_i + 1) ||
                   dfs(board, word, b_i, b_j + 1, w_i + 1) ||
                   dfs(board, word, b_i, b_j - 1, w_i + 1); 

        board[b_i][b_j] = word[w_i];
        return ret;
    }
};
