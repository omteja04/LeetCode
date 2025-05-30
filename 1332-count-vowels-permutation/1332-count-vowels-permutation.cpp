#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast_cin()                                                             \
    std::ios_base::sync_with_stdio(false);                                     \
    std::cin.tie(NULL);                                                        \
    std::cout.tie(NULL)

using Matrix = vector<vector<long long>>;
const int MOD = 1000000007;
using ll = long long;
class Solution {
public:
    Matrix multiply(Matrix& a, Matrix& b) {
        ll n = a.size();
        Matrix res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix generateIdentity(ll n) {
        Matrix I(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            I[i][i] = 1;
        }
        return I;
    }
    Matrix power(Matrix& base, ll exp) {
        Matrix res = generateIdentity(base.size());
        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
    int countVowelPermutation(int n) {
        Matrix transition = {
            {0, 1, 0, 0, 0}, // a -> e
            {1, 0, 1, 0, 0}, // e -> a, i
            {1, 1, 0, 1, 1}, // i -> a, e, o, u
            {0, 0, 1, 0, 1}, // o -> i, u
            {1, 0, 0, 0, 0}  // u -> a
        };

        // Initial vector for n = 1: one of each vowel
        vector<ll> initial = {1, 1, 1, 1, 1};

        if (n == 1)
            return 5;

        Matrix T = power(transition, n - 1);

        ll total = 0;
        for (int i = 0; i < 5; ++i) {
            ll sum = 0;
            for (int j = 0; j < 5; ++j) {
                sum = (sum + T[i][j]) % MOD;
            }
            total = (total + sum) % MOD;
        }

        return total;
    }
};

//     a e i o u
//  a  0 1 0 0 0
//  e  1 0 1 0 0
//  i  1 1 0 1 1
//  o  0 0 1 0 1
//  u  1 0 0 0 0