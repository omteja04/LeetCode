class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(i == nums[i]) continue;
            ans = ans & nums[i];
        }
        return ans == -1 ? 0 : ans;
    }
};