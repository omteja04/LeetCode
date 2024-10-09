import java.util.*;
class Solution {
    public int minAddToMakeValid(String s) {
        int rightCnt = 0;
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ')') {
                if(st.isEmpty()) {
                    rightCnt++;
                }
                else {
                    st.pop();
                }
            } else {
                st.push('(');
            }
        }
        return rightCnt + st.size();
    }
}