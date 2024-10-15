class Solution {
    public long minimumSteps(String s) {
        long black = 0;
        long minSwaps = 0;
        int n = s.length();
        for(int i = 0 ; i < n; i++) {
            if(s.charAt(i) == '1') black++;
            else minSwaps += black;
        }
        return minSwaps;
    }
}