class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int>pre;
        for(int i = 0 ; i < numRows; i++) {
            vector<int> newRow(i + 1, 1);
            for(int j = 1; j < i; j++) {
                newRow[j] = pre[j - 1] + pre[j];
            }
            res.push_back(newRow);
            pre = newRow;
        }
        return res;
    }
};