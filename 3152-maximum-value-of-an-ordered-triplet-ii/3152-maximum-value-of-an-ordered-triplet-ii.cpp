class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n, nums[0]), suffixMax(n, nums[n - 1]);
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << suffixMax[i] << " ";
        // }
        // return 1;
        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            long long val = 1ll * (prefixMax[j - 1] - nums[j]) * suffixMax[j + 1];
            if (val > ans)
                cout << prefixMax[j - 1] << " " << nums[j] << " "
                     << suffixMax[j + 1] << "\n";
            ans = max(ans, val);
        }
        return max(ans, 0LL);
    }
};