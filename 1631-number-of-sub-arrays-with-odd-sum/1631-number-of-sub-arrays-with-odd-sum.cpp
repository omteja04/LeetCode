class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int oddCnt = 0, prefixSum = 0;
        for (auto& it : arr) {
            prefixSum += it;
            oddCnt += prefixSum % 2;
            oddCnt %= MOD;
        }
        oddCnt += (((arr.size() - oddCnt) % MOD) * (oddCnt % MOD)) % MOD;
        oddCnt %= MOD;
        return oddCnt % MOD;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();