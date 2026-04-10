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
    bool isValidBST(TreeNode* root) {
        return isValidBSTRec(root, INT_MIN, INT_MAX);
    }
    bool isValidBSTRec(TreeNode* root, int l, int r) {
        if (!root) return true;
        if (root->val <= l || root->val >= r) return false;
        return isValidBSTRec(root->left, l, root->val) && isValidBSTRec(root->right, root->val, r);

    }
};
