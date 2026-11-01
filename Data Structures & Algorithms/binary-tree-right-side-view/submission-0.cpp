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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        queue<TreeNode*> q;
        vector<int> ret;
        q.push(root);
        
        while(!q.empty()) {
            int cnt = q.size();
            ret.push_back(q.front()->val);
            for (auto i = 0; i < cnt; i++) {
                if(q.front()->right != nullptr) q.push(q.front()->right);
                if(q.front()->left != nullptr) q.push(q.front()->left);
                q.pop();
            }
        }
        return ret;
    }
};
