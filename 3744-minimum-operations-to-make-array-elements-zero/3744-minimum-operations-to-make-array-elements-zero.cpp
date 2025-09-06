class Solution {
public:
    long long stepsSum(long long n) {
        if(n <= 0) return 0;
        long long res= 0 ;
        long long power = 1;
        int k = 1;
        while(true) {
            long long nextPower = power * 4;
            if(n >= nextPower - 1) {
                // Whole Block
                res += (nextPower - power) * 1LL * k;
                power = nextPower;
                k++;
            } else {
                res += (n - power + 1) * 1LL * k;
                break;
            }
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long total = stepsSum(r) - stepsSum(l - 1);
            ans += (total + 1) / 2;
        }
        return ans;
    }
};