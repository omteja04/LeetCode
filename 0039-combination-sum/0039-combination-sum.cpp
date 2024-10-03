class Solution {
public:
 vector<vector<int>> ans;
    // set<vector<int>> ans;
    void search(int i, int n, vector<int>& candidates, int target, int currSum, vector<int>&subset) {
        if (currSum > target) return; 

        if(i >= n) {
            if(currSum == target) {
                // sort(subset.begin(), subset.end());
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(candidates[i]);
        currSum += candidates[i];

        search(i, n, candidates, target, currSum, subset);
        subset.pop_back();
        currSum -= candidates[i];

        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        search(i + 1, n, candidates, target, currSum, subset);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        search(0, candidates.size(), candidates, target, 0, subset);
        
        return ans;
    }
    
};