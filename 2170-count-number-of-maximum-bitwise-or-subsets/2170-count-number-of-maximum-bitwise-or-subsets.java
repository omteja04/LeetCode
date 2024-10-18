class Solution {
    private int cnt = 0;
    private void countSets(int ind, int n, int[] nums, int target, int curr) {
        if(curr > target) return;
        if(ind >= n) {
            if(target == curr) {
                cnt++;
            }
            return;
        }
        countSets(ind + 1, n, nums, target, curr | nums[ind]);
        // while(i + 1 < n && nums[i] === nums[i + 1]) i++;
        countSets(ind + 1, n, nums, target, curr);
    }
    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int target = 0;
        cnt = 0;
        for(int num : nums) {
            target |= num;
        }
        countSets(0, n, nums, target, 0);
        return cnt;
    }
}