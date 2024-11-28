using pi = pair<int, int>;
class Solution {
public:
    bool isValid(int &i, int &j, int &n, int &m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int dijkstra(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> minHeap;
        minHeap.push({0, {0, 0}});
        vector<pi> dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        while(!minHeap.empty()) {
            auto [minDist, idx] = minHeap.top();
            minHeap.pop();
            auto [i, j] = idx;
            for(auto &[x, y] : dir) {
                int X = i + x;
                int Y = j + y;
                if(isValid(X, Y, n, m)) {
                    int newDist = minDist + grid[X][Y];
                    if(newDist < dist[X][Y]) {
                        dist[X][Y] = newDist;
                        minHeap.push({newDist, {X, Y}});
                    }
                }
            }
            // newDist.pop();
        }
        return dist[n - 1][m - 1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};