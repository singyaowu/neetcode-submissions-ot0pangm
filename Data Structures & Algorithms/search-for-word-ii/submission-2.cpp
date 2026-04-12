class Solution {
public:
    struct Node {
        Node* childs[26] = {};
        bool isWord = false;
    };

    void addWord(Node* node, string s) {
        auto cur = node;
        for(auto c : s) {
            if(!cur->childs[c - 'a']) {
                cur->childs[c - 'a'] = new Node();
            }
            cur = cur->childs[c - 'a'];
        }
        cur->isWord = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ret_set;
        auto root = new Node();
        for (auto word : words) {
            addWord(root, word);
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(ret_set, board, root, i, j, "");
            }
        }
        return vector<string>(ret_set.begin(), ret_set.end());
    }

    void dfs(unordered_set<string> &ret_set, vector<vector<char>>& board, Node* node, int x, int y, string out) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '-') {
            return;
        }
        char c = board[x][y];
        if (!node->childs[c - 'a']) {
            return;
        }

        node = node->childs[c - 'a'];
        out += c;
        board[x][y] = '-';
        if (node->isWord) {
            ret_set.insert(out);
            node->isWord = false;
        }
        dfs(ret_set, board, node, x + 1, y, out);
        dfs(ret_set, board, node, x - 1, y, out);
        dfs(ret_set, board, node, x, y + 1, out);
        dfs(ret_set, board, node, x, y - 1, out);
        board[x][y] = c;
    }
};
