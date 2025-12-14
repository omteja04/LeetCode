class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        q.push({n - 1, m - 1});
        cost[n - 1][m - 1] = 0;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int maxEffort = max(cost[x][y], abs(heights[nx][ny] - heights[x][y]));
                     if (cost[nx][ny] > maxEffort) {
                        cost[nx][ny] = maxEffort;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return cost[0][0];

    }
};