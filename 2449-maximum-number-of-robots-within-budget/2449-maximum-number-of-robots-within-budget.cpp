class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        int ans = 0;
        int n = chargeTimes.size();
        deque<int> dq;
        long long sum = 0;
        for (int left = 0, right = 0; right < n; right++) {
            sum += runningCosts[right];
            while (!dq.empty() &&
                   chargeTimes[dq.front()] <= chargeTimes[right]) {
                dq.pop_front();
            }
            dq.push_front(right);

            while (!dq.empty() && left <= right) {
                int maxCost = chargeTimes[dq.back()];
                long long totalCost = maxCost + (right - left + 1) * sum;
                if (totalCost <= budget)
                    break;
                sum -= runningCosts[left];
                if (dq.back() == left)
                    dq.pop_back();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
