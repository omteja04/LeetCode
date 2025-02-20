class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int sum = INT_MIN;
        while(left < right) {
            int s = nums[left] + nums[right];
            sum = max(sum, s);
            left++;
            right--;
        }
        return sum;
    }
};