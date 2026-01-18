class Solution {
public:
    inline bool isMagic(int r, int c, vector<vector<int>>& g) {
        // 1️⃣ center must be 5
        if (g[r+1][c+1] != 5) return false;

        // 2️⃣ parity rules
        if ((g[r][c] & 1) || (g[r][c+2] & 1) ||
            (g[r+2][c] & 1) || (g[r+2][c+2] & 1))
            return false; // corners even

        if (!(g[r][c+1] & 1) || !(g[r+1][c] & 1) ||
            !(g[r+1][c+2] & 1) || !(g[r+2][c+1] & 1))
            return false; // edges odd

        // 3️⃣ uniqueness 1..9
        bool seen[10] = {0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = g[r+i][c+j];
                if (x < 1 || x > 9 || seen[x]) return false;
                seen[x] = true;
            }
        }

        // 4️⃣ opposite cells must sum to 10
        if (g[r][c]     + g[r+2][c+2] != 10) return false;
        if (g[r][c+2]   + g[r+2][c]   != 10) return false;
        if (g[r][c+1]   + g[r+2][c+1] != 10) return false;
        if (g[r+1][c]   + g[r+1][c+2] != 10) return false;

        // 5️⃣ FINAL REQUIRED CHECK: all rows & cols = 15
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != 15)
                return false;
            if (g[r][c+i] + g[r+1][c+i] + g[r+2][c+i] != 15)
                return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                cnt += isMagic(i, j, grid);
            }
        }
        return cnt;
    }
};
