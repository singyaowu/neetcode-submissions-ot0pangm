class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> rnk(n, 1);
        for(auto i = 0; i < n; i++) par[i] = i;
        
        auto find = [&par, &rnk](int v) {
            while(par[v] != v) {
                par[v] = par[par[v]];
                v = par[v];
            }
            return v;
        };
        auto union_set = [&par, &rnk, find](int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return 0;
            if (rnk[u] < rnk[v]) {
                swap(u, v);
            }
            par[v] = u;
            rnk[u] += rnk[v];
            return 1;
        };
        int ret = n;
        for(auto edge: edges) {
            ret -= union_set(edge[0], edge[1]);
        }
        return ret;
    }
};
