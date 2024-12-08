class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        int vis[n][m];
        queue<tuple<int, int, int>> q;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j< m; j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j, 0});
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            // int row = get<0>(q.front());
            // int col = get<1>(q.front());
            // int steps = get<2>(q.front());
            auto [row, col, steps] = q.front();
            q.pop();
            dist[row][col] = steps;

            for(int i = 0 ; i  < 4; i++) {
                int x = row + drow[i];
                int y = col + dcol[i];
                if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0) {
                    vis[x][y] = 1;
                    q.push({x, y, steps + 1});
                }
            }
        }
        return dist;
    }
};