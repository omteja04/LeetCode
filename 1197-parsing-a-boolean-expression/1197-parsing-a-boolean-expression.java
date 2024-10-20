import java.util.*;
class Solution {
    private char outputBoolean(char operator, ArrayList<Character> operands) {
        if(operator == '!') {
            return operands.get(0) == 't' ? 'f' : 't';
        }

        if(operator == '|') {
            return operands.stream().anyMatch(ch -> ch == 't') ? 't' : 'f';
        }

        if(operator == '&') {
            return operands.stream().anyMatch(ch -> ch == 'f') ? 'f' : 't';
        }
        return 't';
    }
    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();
        int expLen = expression.length();
        for(int i = 0 ; i  < expLen; i++) {
            if(expression.charAt(i) == ',') {
                continue;
            } else if(expression.charAt(i) == ')') {
                ArrayList<Character> operands = new ArrayList<Character>();

                while(st.peek() != '(') {
                    Character ch = st.peek();
                    st.pop();
                    operands.add(ch);
                }
                st.pop();
                char operator = st.peek();
                st.pop();
                st.add(outputBoolean(operator, operands));
            } else {
                st.add(expression.charAt(i));
            }
        }
        return st.peek() == 't';
    }
}