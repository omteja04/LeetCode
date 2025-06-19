class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int i = 0;
        while (i < nums.size()) {
            i = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
            cnt++;
        }
        return cnt;
    }
};