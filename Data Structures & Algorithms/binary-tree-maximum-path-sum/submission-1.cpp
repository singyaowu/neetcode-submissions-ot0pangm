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
    int maxPathSum(TreeNode* root) {
        int ret = root->val;
        dfs(root, ret);
        return ret;
    }
    int dfs(TreeNode*node, int &max_path) {
        int left = 0, right = 0;
        if(node->left) {
            left = dfs(node->left, max_path);
        }
        if(node->right) {
            right = dfs(node->right, max_path);
        }
        int max_to_node = node->val + max(max(left, right), 0);
        max_path = max(max_path, max(max_to_node, left + node->val + right));
        return max_to_node;
    }
};
