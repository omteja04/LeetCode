class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> preprocess(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                preprocess[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowFreq(m, 0), colFreq(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            int x = preprocess[num].first;
            int y = preprocess[num].second;

            rowFreq[x]++;
            colFreq[y]++;

            if (rowFreq[x] == n) {
                return i;
            }
            if (colFreq[y] == m) {
                return i;
            }
        }
        return -1;
    }
};