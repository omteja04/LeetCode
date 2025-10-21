class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> diff(2 * 1e5, 0);
        unordered_map<int, int> freq;
        int maxFreq = -1;
        int maxEle = -1;
        for (auto& ele : nums) {
            int mini = ele - k;
            int maxi = ele + k;
            if (mini < 0) {
                diff[0]++;
            } else {
                diff[mini]++;
            }             
            diff[maxi + 1]--;
            freq[ele]++;
            maxFreq = max(maxFreq, freq[ele]);
            maxEle = max(maxEle, ele);
        }
        int maxiAns = 0;
        for (int i = 1; i <= maxEle + k; i++) {
            diff[i] += diff[i - 1];
            maxiAns = max(maxiAns, min(diff[i], freq[i] + numOperations));
        }

        int ans = min(maxiAns, maxFreq + numOperations);
        return ans;
    }
};