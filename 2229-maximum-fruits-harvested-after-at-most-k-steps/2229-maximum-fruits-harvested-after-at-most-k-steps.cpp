class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> positions(n);
        vector<int> prefix(n + 1,  0);
        for(int i = 0; i < n; i++) {
            positions[i] = fruits[i][0];
        }
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }
        
        auto getSum = [&](int left, int right) -> int {
            auto l = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            auto r = upper_bound(positions.begin(), positions.end(), right) - positions.begin() - 1;

            return (l <= r) ? (prefix[r + 1] - prefix[l]) : 0;
        };

        int ans = 0;
        for(int x = 0; x <= k; x++) {

            // [startPos - (k + 2x), startPos + x];
            ans = max(ans, getSum(startPos - max(0, (k - 2 * x)), startPos + x));
            // [startPos - x, startPos + (k + 2x)];
            ans = max(ans, getSum(startPos - x, startPos + max(0, (k - 2 * x))));
        }
        return ans;

    }
};