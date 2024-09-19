class Solution {

public:
    const int MOD = 1000000007;
    int noOfBits(int n) {
        return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            int length = noOfBits(i);
            ans = ((ans << length) % MOD + i);
        }
        return ans;
    }
};