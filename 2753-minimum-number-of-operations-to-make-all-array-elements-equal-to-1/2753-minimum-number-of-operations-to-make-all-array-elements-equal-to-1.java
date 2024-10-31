class Solution {
    public int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);

    }
    public int minOperations(int[] nums) {
        int one = 0, n = nums.length;
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) one++;
        }

        if(one != 0) return n - one;

        for(int i = 0 ; i  < n; i++) {
            int val = nums[i];
            for(int j = i + 1; j  < n; j++) {
                val = gcd(val, nums[j]);
                if(val == 1) {
                    ans = Integer.min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : n - 1 + (ans - 1);
        
    }
}