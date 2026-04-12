/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visit;
        return dfs(visit, node);
    }
    Node* dfs(unordered_map<Node*, Node*> &visit, Node* node) {
        if (!node) return nullptr;
        if (visit.count(node))
            return visit[node];

        int val = node->val;
        auto copy = new Node(val);
        visit[node] = copy;
        for (auto neib : node->neighbors) {
            copy->neighbors.push_back(dfs(visit, neib));
        }
        return copy;
    }
};
