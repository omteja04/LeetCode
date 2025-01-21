class Solution {
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> res;
        std::multiset<long long> low, high;
        auto balance = [&] {
            if (low.size() > high.size() + 1) {
                high.insert(*low.rbegin());
                low.erase(std::prev(low.end()));
            } else if (high.size() > low.size()) {
                low.insert(*high.begin());
                high.erase(high.begin());
            }
        };
        for (int i = 0; i < nums.size(); i++) {
            // insertion
            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.emplace(nums[i]);
            } else {
                high.emplace(nums[i]);
            }
            balance();
            // deletion
            if (i >= k) {
                int val = nums[i - k];
                if (val <= *low.rbegin()) {
                    low.erase(low.find(val));
                } else {
                    high.erase(high.find(val));
                }
            }
            balance();
            if (i >= k - 1) {
                if (k & 1) {
                    res.emplace_back((double)*prev(low.end()));
                } else {
                    res.emplace_back(
                        ((double)*prev(low.end()) + (double)(*high.begin())) /
                        2.0);
                }
            }
        }

        return res;
    }
};