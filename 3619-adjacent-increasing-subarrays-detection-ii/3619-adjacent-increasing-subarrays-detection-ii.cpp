class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int inc = 1, prevInc = 0, maxi = 1;
        int n = nums.size();
        bool split = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                split = true;
                prevInc = inc;
                inc = 1;
            }
            if (prevInc && inc) {
                maxi = max(maxi, min(inc, prevInc));
            }
            if (inc >= 2) {
                maxi = max(maxi, inc / 2);
            }
        }
        return maxi;
    }
};