class Solution {
public:
bool isValid(pair<int, int> & cell, int r, int c) {
    return cell.first >= 0 && cell.second >= 0 && cell.first < r &&
               cell.second < c;
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<int> dx, dy;
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};
        int r = isWater.size();
        int c = isWater[0].size();

        vector<vector<int>> heights(r, vector<int>(c, -1));
        queue<pair<int, int>> q;
        for(int x = 0; x < r; x++) {
            for(int y = 0; y < c; y++) {
                if(isWater[x][y]) {
                    q.push({x, y});
                    heights[x][y] = 0;
                }
            }
        }
        int heightOfLayer = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    pair<int, int> nextCell = {p.first + dx[d], p.second + dy[d]};

                    if(isValid(nextCell, r, c) && heights[nextCell.first][nextCell.second] == -1) {
                        heights[nextCell.first][nextCell.second] = heightOfLayer;
                        q.push(nextCell);
                    }
                 }
            }
            heightOfLayer++;
        }
        return heights;
    }
};