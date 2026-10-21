class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = 0, j = 0;
        while (true) {
            char dir = grid[i][j];
            grid[i][j] = 'X';

            if (dir == 'L')
                j--;
            else if (dir == 'R')
                j++;
            else if (dir == 'U')
                i--;
            else if (dir == 'D')
                i++;
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X') {
                return {i - (dir == 'D') + (dir == 'U'),
                        j - (dir == 'R') + (dir == 'L')};
            }
        }
    }
};