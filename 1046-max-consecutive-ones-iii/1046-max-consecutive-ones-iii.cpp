class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones = 0;
        int zeros = 0;
        int n = nums.size();
        int ans = 0;
        for(int left = 0, right = 0; right < n; right++) {
            if(nums[right] == 0) zeros++;
            cout << zeros <<" ";
            if(zeros  > k) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;

            }
            ans = max(ans, right- left + 1);
        }
        return ans;
    }
};