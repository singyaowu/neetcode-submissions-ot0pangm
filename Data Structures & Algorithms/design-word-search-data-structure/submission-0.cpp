class WordDictionary {
public:
    struct Node {
        Node* child[26] = {};
        bool isWord = false;
    };

    Node* root = new Node();

    WordDictionary() {}
    
    void addWord(string word) {
        auto cur = root;
        for (auto c: word) {
            if (!cur->child[c-'a'])
                cur->child[c-'a'] = new Node();
            cur = cur->child[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(const string &word, int idx, Node* node) {
        if (idx == word.size()) {
            return node->isWord;
        }
        if (word[idx] == '.') {
            for (auto child : node->child) {
                if (child && dfs(word, idx+1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            auto child = node->child[word[idx] - 'a'];
            return child && dfs(word, idx + 1, child);
        }
    }

};
