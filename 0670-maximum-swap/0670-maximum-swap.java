class Solution {
    public int maximumSwap(int num) {
        String number = Integer.toString(num);
        int leftIdx = -1;
        int rightIdx = -1;
        int rightMostMaxNum = -1;
        int rightMostMaxIdx = -1;
        int n = number.length();
        for(int i = n - 1; i >=0; i--) {
            if(number.charAt(i) - '0' > rightMostMaxNum) {
                rightMostMaxNum = number.charAt(i) - '0';
                rightMostMaxIdx = i;
            } else if(number.charAt(i) - '0' < rightMostMaxNum) {
                leftIdx = i;
                rightIdx = rightMostMaxIdx;
            }
        }
        if(leftIdx == -1) return num;
        StringBuilder str = new StringBuilder(number);
        str.setCharAt(leftIdx, number.charAt(rightIdx));
        str.setCharAt(rightIdx, number.charAt(leftIdx));
        number = str.toString();
        return Integer.parseInt(number);
    }

}