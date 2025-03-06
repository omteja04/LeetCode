class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        int expectedSum = N * (N + 1) / 2;
        int expectedSquaredSum = (long long) N * (N + 1) * (2 * N + 1) / 6;
        int actualSum = 0;
        int actualSquaredSum = 0;
        for(auto &row : grid) {
            for(auto &num : row) {
                actualSum += num;
                actualSquaredSum += (long long)num * num;
            }
        }
        int difference = actualSum - expectedSum;
        int diffSq = actualSquaredSum - expectedSquaredSum;
        int additionOf2Nums = diffSq / difference;
        int a = (difference + additionOf2Nums) / 2;
        int b = (-difference + additionOf2Nums) / 2;
        return {a, b};
    }
};