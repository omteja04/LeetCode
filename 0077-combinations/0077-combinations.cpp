class Solution {
public:
 vector<vector<int>> ans;
void search(int st, int n, int target,  vector<int>&subset) {
        // if (i > target) return; 

        if(subset.size() == target) {
            // return;
                ans.push_back(subset);
                return;
        }

        for(int i = st; i <= n; i++){
            subset.push_back(i);
            search(i + 1, n, target, subset);
            subset.pop_back();
        }


        // search(i + 1, n, target, subset);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        // sort(candidates.begin(), candidates.end());
        search(1, n, k, subset);
        
        return ans;
        
    }
};