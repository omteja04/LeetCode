class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, int>> damageAndTime;

        // Create pairs of (damage, time to kill)
        for (int i = 0; i < n; ++i) {
            // Calculate time to kill the enemy
            int timeToKill = (health[i] + power - 1) / power;
            damageAndTime.push_back({damage[i], timeToKill});
        }

        // Sort pairs by damage in descending order
        sort(damageAndTime.begin(), damageAndTime.end(), [](const pair<int,int> &a, const pair<int, int> &b) {
            return (double) a.first / a.second > (double) b.first / b.second;
        });

        // Calculate the total damage

        long long totalDamage = 0;
        for (int i = 0; i < n; i++) {
            totalDamage += damageAndTime[i].first;
        }
        long long ans = 0;
        for (const auto& [dmg, timeToKill] : damageAndTime) {
            ans += (long long)totalDamage * timeToKill;
            totalDamage -= dmg;

        }
        return ans;
    }
};
