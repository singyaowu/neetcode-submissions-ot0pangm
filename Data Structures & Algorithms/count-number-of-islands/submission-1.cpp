class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    deleteIsland(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    void deleteIsland(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        const vector<pair<int, int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [x_dir, y_dir] : dirs) {
                auto next_x = x + x_dir;
                auto next_y = y + y_dir;
                if (next_x >= 0 && next_x < grid.size() && 
                        next_y >= 0 && next_y < grid[0].size() && 
                            grid[next_x][next_y] == '1') {
                    q.push({next_x, next_y});
                    grid[next_x][next_y] = '0';
                }
            }
        }
    }
};
