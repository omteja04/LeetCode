class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = Arrays.stream(rolls).sum();
        int total = rolls.length + n;
        int needed = mean * total - sum;
        int[] ans = new int[n];
        if (needed < n || needed > (n * 6))
            return new int[]{};
        else {
            int full = needed / n;
            int extra = needed % n;
            for (int i = 0; i < n; i++) {
                if (extra > 0)
                    ans[i] = full + 1;
                else
                    ans[i] = full;
                extra = Math.max(0, extra - 1);
            }
        }
        return ans;
    }
}