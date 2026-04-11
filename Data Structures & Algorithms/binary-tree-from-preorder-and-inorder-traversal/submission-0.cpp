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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        int pre_i = 0;
        return dfs(preorder, inorder_map, 0, preorder.size(), pre_i);
    }

    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int> &inorder_map, int l, int r, int &pre_i) {
        if (l == r) {
            return nullptr;
        }
        int val = preorder[pre_i++];
        auto node = new TreeNode(val);
        auto mid = inorder_map[val];
        node->left = dfs(preorder, inorder_map, l, mid, pre_i);
        node->right = dfs(preorder, inorder_map, mid+1, r, pre_i);
        return node;
    }
};
