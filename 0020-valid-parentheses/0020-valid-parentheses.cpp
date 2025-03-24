class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch :s)
        {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if(stk.empty()) return false;
                if(ch == ')' && stk.top() == '(') stk.pop();
                else if (ch == ']' && stk.top() == '[') stk.pop();
                else if(ch == '}' && stk.top() == '{') stk.pop();
                else return false;
            }
        }
        if (stk.empty())return true;
        else return false;
    }
};