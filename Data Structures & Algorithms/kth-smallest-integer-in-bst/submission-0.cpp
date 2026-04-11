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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return INT_MIN;
        return recur(root, k);
    }
    int recur(TreeNode*root, int &cnt) {
        if (!root) return INT_MIN;
        int left_ret = recur(root->left, cnt);
        if (cnt == 0) return left_ret;
        cnt--;
        if (cnt == 0) return root->val;
        return recur(root->right, cnt);
    }
};
