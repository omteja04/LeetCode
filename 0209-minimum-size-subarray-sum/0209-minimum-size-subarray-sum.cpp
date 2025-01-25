class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        for(int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while(left <= right && sum >= target) {
                sum -= nums[left];
                ans = min(ans, right - left + 1);
                left++;
            }
            cout << sum <<" ";
        }
        return ans == n + 1 ? 0 : ans;
    }
};