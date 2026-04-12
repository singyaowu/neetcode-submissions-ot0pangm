class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) return true;
        vector<bool> visited(n, false);
        vector<vector<int>> adj_list(n, vector<int>());
        for (auto edge : edges) {
            auto v1 = edge[0], v2 = edge[1];
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        if (!dfs(visited, adj_list, 0, -1))
            return false;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
    bool dfs(vector<bool> &visited, vector<vector<int>> &adj_list, int cur, int parent) {
        visited[cur] = true;
        for (auto v: adj_list[cur]) {
            if (v == parent) continue;
            if (visited[v]) return false;
            if( !dfs(visited, adj_list, v, cur) ) return false;
        }
        return true;
    }
};
