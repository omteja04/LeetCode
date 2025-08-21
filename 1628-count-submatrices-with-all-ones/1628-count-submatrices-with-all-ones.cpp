class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> hist(n, 0);
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                hist[j] = mat[i][j] ? 1 + hist[j] : 0;
            }
            for(int j = 0; j < n; j++) {
                int mn = hist[j];
                for(int k = j; k >= 0 && mn > 0; k--) {
                    mn = min(mn, hist[k]);
                    cnt += mn;
                }
            }
        }
        return cnt;
    }
};