class Solution {
    public int missingNumber(int[] nums) {
        int x = 0;
        for(int i = 1; i <= nums.length; i++) {
            x ^= i;
        }
        for(int i : nums) {
            x ^= i;
        }
        return x;
    }
}