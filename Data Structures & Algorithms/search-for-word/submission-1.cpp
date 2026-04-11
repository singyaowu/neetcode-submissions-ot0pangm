class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, string &word, int b_i, int b_j, int w_i) {
        if (board[b_i][b_j] != word[w_i])
            return false;
        if (w_i == word.size() - 1)
            return true;

        board[b_i][b_j] = '-';
        vector<pair<int, int>> dirs({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
        for (auto [d_i, d_j]: dirs){
            auto nb_i = b_i + d_i, nb_j = b_j + d_j;
            if (nb_i >= 0 && nb_i < board.size() && nb_j >= 0 && nb_j < board[0].size()) {
                if (dfs(board, word, nb_i, nb_j, w_i + 1)) return true;
            }
        }
        board[b_i][b_j] = word[w_i];
        return false;
    }
};
