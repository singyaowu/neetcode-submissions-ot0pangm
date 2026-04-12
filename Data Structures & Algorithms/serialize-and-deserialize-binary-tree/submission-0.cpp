/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfs(data, idx);
    }
    TreeNode* dfs(string &data, int &idx) {
        if (data[idx] == 'N') {
            idx += 2;
            return nullptr;
        }
        int start = idx;
        while(data[idx] != ',') {
            idx++;
        }
        int val = stoi(data.substr(start, idx - start));
        auto node = new TreeNode(val);
        idx++;
        node->left = dfs(data, idx);
        node->right = dfs(data, idx);
        return node;
    }
};
