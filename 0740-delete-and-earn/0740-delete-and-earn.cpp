class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> uniq;
        for (int& x : nums) {
            mp[x] += x;
            if (mp[x] == x)
                uniq.push_back(x);
        }
        sort(uniq.begin(), uniq.end());
        long long prev1 = 0, prev2 = 0;
        for (int i = 0; i < uniq.size(); i++) {
            long long points = mp[uniq[i]];
            long long taken = points;
            if (i > 0 && uniq[i - 1] + 1 == uniq[i]) {
                taken += prev2;
            } else {
                taken += prev1;
            }
            long long skip = prev1;
            long long curr = max(skip, taken);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};