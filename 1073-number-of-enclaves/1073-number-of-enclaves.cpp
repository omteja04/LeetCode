class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() ||
            vis[i][j] || grid[i][j] == 0) {
            return;
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vis[i][j] = true;
        for (auto [dx, dy] : dir) {
            int x = i + dx;
            int y = j + dy;
            dfs(x, y, grid, vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, grid, vis);
            if (!vis[i][n - 1] && grid[i][n - 1] == 1)
                dfs(i, n - 1, grid, vis);
        }
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, grid, vis);
            if (!vis[m - 1][j] && grid[m - 1][j] == 1)
                dfs(m - 1, j, grid, vis);
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};