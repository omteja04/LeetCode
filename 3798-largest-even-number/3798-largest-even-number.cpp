class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int x = n;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                x--;
                cout << x << " ";
            }
            else break;
        }
        return s.substr(0, x);
        
    }
};
