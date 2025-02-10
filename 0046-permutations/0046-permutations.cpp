class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    void solve(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {
                continue;
            }
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(nums, temp);
            st.erase(nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp);
        return ans;
    }
};