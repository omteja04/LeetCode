class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

		vector<int> prev(n, 0);
	
		for(int row = 0; row < m; row++) {
			vector<int> curr(n, 0);
			for(int col = 0; col  < n; col++) {
                if(grid[row][col] == 1) {
                    curr[col] = 0;
                    continue;
                }
                if(row == 0 && col == 0){ curr[col] = 1;
                continue;}
                int up  = 0;
                int left = 0;
                if(col > 0) {
                    left = curr[col - 1];
                }
                if(row > 0) {
                    up = prev[col];
                }
                curr[col] = left + up;
			}
			prev = curr;
		}
		return prev[n - 1];
    }
};