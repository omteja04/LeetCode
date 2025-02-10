class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int currSum, int n, vector<int>& candidates, int target, vector<int>& subset) {
        if(currSum > target) return;
        if(idx >= n) {
            if(currSum == target) {
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(candidates[idx]);
        solve(idx, currSum + candidates[idx], n, candidates, target, subset);
        subset.pop_back();
        solve(idx + 1, currSum, n, candidates, target, subset);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, 0, n, candidates, target, subset);
        return ans;
    }
};