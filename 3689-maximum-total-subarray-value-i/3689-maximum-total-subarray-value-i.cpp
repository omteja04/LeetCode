class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto &it : nums) {
            maxi = max(maxi, it);
            mini = min(mini, it);
        }
        return (long long)k * (maxi - mini);
    }
};