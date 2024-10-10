import java.util.*;
class Solution {
    public int maxWidthRamp(int[] nums) {
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < nums.length; i++) {
            if(st.isEmpty() || nums[st.peek()] > nums[i]) st.push(i);
        }
        int maxLen = 0;
        for(int j = nums.length - 1; j >= 0; j--) {
            while(!st.isEmpty() && nums[j] >= nums[st.peek()]) {
                maxLen = Integer.max(maxLen, j - st.peek());
                st.pop();
            }
        }
        return maxLen;
    }
}