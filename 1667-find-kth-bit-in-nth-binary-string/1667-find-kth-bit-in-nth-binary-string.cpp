class Solution {
public:
    string invert(string &s) {
        string str = "";
        for(char &ch : s) {
            if(ch == '1') str += "0";
            else str += "1";
        }
        return str;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        if(n == 1) return s[0];
        if(k == 1) return s[0];
        for(int i = 2; i <= n; i++) {
            string str = invert(s);
            reverse(str.begin(), str.end());
            s = s + "1" + str;
            // cout << s << endl;
        }
        return s[k - 1];
    

    }
};