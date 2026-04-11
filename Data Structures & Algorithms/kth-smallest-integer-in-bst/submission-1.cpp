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
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});

        while(!s.empty()) {
            auto [node, left_done] = s.top();
            if (!left_done && node->left) {
                s.top().second = true;
                s.push({node->left, false});
            } else {
                k--;
                if (k == 0) return node->val;
                s.pop();
                if (node->right)
                    s.push({node->right, false});
            }
        }
        return INT_MIN;
    }

};
