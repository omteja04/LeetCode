class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        set<pair<int, int>> st;
        int element = INT_MAX;
        for(int i = 0; i < k; i++) {
            st.insert({nums[i], i});
        }
        res.push_back(st.rbegin() -> first);
        for(int i = k ; i < nums.size(); i++) {
            st.erase({nums[i - k], i - k});
            st.insert({nums[i], i});
            res.push_back(st.rbegin() -> first);
        }
        return res;
        

    }
};