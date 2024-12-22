class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int last = INT_MIN;
        for(int i = 0 ; i  < nums.size(); i++) {
            int mn = nums[i] - k;
            int mx = nums[i] + k;
            if(last < mn) {
                last = mn;
                ans++;
            }
            else if(last < mx) {
                last = last + 1;
                ans++;
            }
        }
        return ans;

    }
};