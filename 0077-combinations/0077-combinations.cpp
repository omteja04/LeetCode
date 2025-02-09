class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, int end, int target, vector<int> &subset) {
        if(subset.size() == target) {
            ans.push_back(subset);
            return;
        }
        for(int i = start; i <= end; i++) {
            subset.push_back(i);
            solve(i + 1, end, target, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        solve(1, n, k, subset);
        return ans;
    }
};