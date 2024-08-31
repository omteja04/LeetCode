class Solution {
public:
    static bool custom(const vector<int> &a, const vector<int> &b, int power) {
        int A = a[0] * ((b[1] + power - 1) / power);
        int B = b[0] * ((a[1] + power - 1) / power);
        return B < A;
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<vector<int>> enemy;
        for (int i = 0; i < n; i++) {
            enemy.push_back({damage[i], health[i]});
        }
        sort(enemy.begin(), enemy.end(), [power](const vector<int>& a, const vector<int>& b) {
            return custom(a, b, power);
        });

        long long total = 0;
        long long cur = 0;
        for (auto i : enemy) {
            cur += i[0];
        }
        for (auto i : enemy) {
            int d = (i[1] + power - 1) / power;
            total += d * cur;
            cur -= i[0];
        }
        return total;
    }
};
