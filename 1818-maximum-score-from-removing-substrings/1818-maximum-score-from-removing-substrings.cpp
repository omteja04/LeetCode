class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int gScore = max(x,y);
        int lScore = min(x,y);

        char firstChar, secondChar;

        if(gScore == x) {
            firstChar = 'a';
            secondChar = 'b';
        } else {
            firstChar = 'b';
            secondChar = 'a';
        }

        stack<char>stk;
        int ans = 0;

        for(int i = 0 ; i  < s.length() ;i ++) {
            if(!stk.empty() && stk.top() == firstChar && s[i] == secondChar) {
                ans += gScore;
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        stack<char> stkRev;
        while(!stk.empty()) {
            if(!stkRev.empty() && stkRev.top() == firstChar && stk.top() == secondChar) {
                ans += lScore;
                stkRev.pop();
            } else {
                stkRev.push(stk.top());
            }
            stk.pop();
        }
        return ans;

    }
};