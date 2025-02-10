class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &vis) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] == 1 || board[i][j] == 'X') return;

        vis[i][j] = true;
        int m = board.size();
        int n = board[0].size();

        int dRow[4] = {1, 0, -1, 0};
        int dCol[4] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {
            int x = i + dRow[k];
            int y = j + dCol[k];
            
            dfs(x, y, board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && vis[i][0] == false) {
                dfs(i, 0, board, vis);
            }
            if(vis[i][n - 1] == false && board[i][n - 1] == 'O') {
                dfs(i, n - 1, board, vis);
            }
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && vis[0][j] == false) {
                dfs(0, j, board, vis);
            }
            if(vis[m - 1][j] == false && board[m - 1][j] == 'O') {
                dfs(m - 1, j, board, vis);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j  <n; j++) {
                if(board[i][j] == 'O' && vis[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }


    }
};