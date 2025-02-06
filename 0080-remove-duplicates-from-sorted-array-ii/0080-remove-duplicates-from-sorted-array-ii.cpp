class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int cnt = 0;
        int current = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                cnt = 0;
                nums[current++] = nums[i];
            } else {
                cnt++;
                if(cnt <= 1) {
                    nums[current++] = nums[i];
                }
            }
        }
        return current;
    }
};