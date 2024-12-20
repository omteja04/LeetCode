using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll low = min(a, b);
        ll high = low *1LL * n;
        ll LCM = 1LL* (a*b) / __gcd(a, b);
        ll ans = 0;
        auto nums = [&](ll x) {return x / a + x / b  - x / LCM; };
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(nums(mid) < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans % MOD;

    }
};