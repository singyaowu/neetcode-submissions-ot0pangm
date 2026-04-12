class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (!m) return vector<vector<int>>();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for(int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j, INT_MIN);
            dfs(heights, atl, m-1, j, INT_MIN);
        }
        for(int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0, INT_MIN);
            dfs(heights, atl, i, n-1, INT_MIN);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j])
                    ret.push_back({i, j});
            }
        }
        return ret;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &sea, int x, int y, int prev) {
        if (x < 0 || y < 0 || x == heights.size() || y == heights[0].size())
            return;
        if (sea[x][y])
            return;
        if (heights[x][y] >= prev) {
            sea[x][y] = true;
            dfs(heights, sea, x + 1, y, heights[x][y]);
            dfs(heights, sea, x - 1, y, heights[x][y]);
            dfs(heights, sea, x, y + 1, heights[x][y]);
            dfs(heights, sea, x, y - 1, heights[x][y]);
        }
    }
};
