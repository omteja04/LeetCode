class Solution {
public:
    unordered_map<int, int> dp;
    int memo(int ind, int n, vector<vector<int>>& jobs) {
        if (ind == n)
            return 0;
        if (dp.count(ind)) {
            return dp[ind];
        }
        int nextJob = findNext(jobs, jobs[ind][1]);

        int pick = jobs[ind][2] + memo(nextJob, n, jobs);
        int dontPick = memo(ind + 1, n, jobs);

        dp[ind] = max(pick, dontPick);
        return dp[ind];
    }
    int findNext(vector<vector<int>>& jobs, int endTime) {
        int low = 0;
        int high = jobs.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= endTime) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        return memo(0, n, jobs);
    }
};