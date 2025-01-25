class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        // set<pair<int, int>> st;
        // int element = INT_MAX;
        // for(int i = 0; i < k; i++) {
        //     st.insert({nums[i], i});
        // }
        // res.push_back(st.rbegin() -> first);
        // for(int i = k ; i < nums.size(); i++) {
        //     st.erase({nums[i - k], i - k});
        //     st.insert({nums[i], i});
        //     res.push_back(st.rbegin() -> first);
        // }

        std::deque<int> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // std::cout << dq.front() + 1 << " ";
        res.push_back(nums[dq.front()]);
        for (int i = k; i < n; i++) {
            if (i - k == dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
            // std::cout << dq.front() + 1 << " ";
        }
            return res;
    }
};