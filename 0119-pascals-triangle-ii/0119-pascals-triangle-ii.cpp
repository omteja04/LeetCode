class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>pre;
        for(int i = 0 ; i <= rowIndex; i++) {
            vector<int> newRow(i + 1, 1);
            for(int j = 1; j < i; j++) {
                newRow[j] = pre[j - 1] + pre[j];
            }
            // res.push_back(newRow);
            pre = newRow;
        }
        return pre;
    }
};