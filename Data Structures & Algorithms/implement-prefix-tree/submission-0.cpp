class PrefixTree {
public:
    struct Node {
        Node* childs[26] = {};
        bool isWord = false;
    };

    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (auto c: word) {
            if (!cur->childs[c - 'a']) {
                cur->childs[c - 'a'] = new Node();
            }
            cur = cur->childs[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (auto c: word) {
            if (!cur->childs[c-'a']) return false;
            cur = cur->childs[c-'a'];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (auto c: prefix) {
            if (!cur->childs[c-'a']) return false;
            cur = cur->childs[c-'a'];
        }
        return true;
    }
};
