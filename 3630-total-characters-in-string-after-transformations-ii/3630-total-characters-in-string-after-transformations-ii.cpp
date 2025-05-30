
using ll = long long;
using Matrix = vector<vector<ll>>;

class Solution {
public:
    const int MOD = 1e9 + 7;

    Matrix multiply(const Matrix& a, const Matrix& b) {
        ll n = a.size();
        ll m = b[0].size();
        ll p = b.size();
        Matrix res(n, vector<ll>(m, 0));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                for (ll k = 0; k < p; k++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix generateIdentity(ll n) {
        Matrix I(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; ++i)
            I[i][i] = 1;
        return I;
    }

    Matrix power(Matrix base, ll exp) {
        Matrix res = generateIdentity(base.size());
        while (exp) {
            if (exp & 1)
                res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix T(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < nums[i]; j++) {
                T[i][(i + 1 + j) % 26]++;
            }
        }

        Matrix freq(1, vector<ll>(26, 0));
        for (char ch : s)
            freq[0][ch - 'a']++;

        Matrix transform = power(T, t);
        freq = multiply(freq, transform);

        ll total = 0;
        for (ll cnt : freq[0])
            total = (total + cnt) % MOD;
        return static_cast<int>(total);
    }
};