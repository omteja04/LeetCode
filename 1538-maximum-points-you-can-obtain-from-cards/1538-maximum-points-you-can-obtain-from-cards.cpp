class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int currSum = 0;
        int ans = 0;
        for(int i = 0; i < k; i++) {
            currSum += arr[i];
        }
        ans = currSum;
        for(int i = k - 1; i >= 0; i--) {
            currSum -= arr[i];
            currSum += arr[arr.size() - k + i];
            ans = max(currSum, ans);
        }
        return ans;
    }
};