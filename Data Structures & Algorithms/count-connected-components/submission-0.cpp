class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visit(n, false);
        vector<vector<int>> adj_list(n, vector<int>());
        for (auto edge : edges) {
            auto v1 = edge[0], v2 = edge[1];
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                ret++;
                dfs(visit, adj_list, i);
            }
        }
        return ret;
    }
    void dfs(vector<bool> &visit, const vector<vector<int>> &adj_list, int cur) {
        visit[cur] = true;
        for(auto v : adj_list[cur]) {
            if (!visit[v])
                dfs(visit, adj_list, v);
        }
    }
};
