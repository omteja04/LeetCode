class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int left, right;
        vector<int>prefix(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        vector<int>ans;
        for(auto &Q : queries) {
            left = Q[0];
            right = Q[1] + 1;

            ans.push_back(prefix[left] ^ prefix[right]);
        }
        return ans;
    }
};