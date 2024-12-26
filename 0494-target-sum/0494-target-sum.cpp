class Solution {
public:
    int helper(std::vector<int> &arr, int target, int idx, int sum) {
        if(idx == arr.size()) {
            return sum == target ? 1 : 0;
        }
        int add = helper(arr, target, idx + 1, sum + arr[idx]);
        int sub = helper(arr, target, idx + 1, sum - arr[idx]);
        return add + sub;
    }
    int findTargetSumWays(std::vector<int> &nums, int target) {
        return helper(nums, target, 0, 0);
    }
};