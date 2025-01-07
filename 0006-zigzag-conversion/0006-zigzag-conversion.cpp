class Solution {
public:
    string convert(string str, int m) {
        if(m == 1) return str;
        std::vector<std::string> arr(m);
        bool isForward = true;
        int k = -1;
        for(int i = 0; i < str.size(); i++) {
            if(isForward) {
                arr[++k] += str[i];
                if(k == m - 1) {
                    isForward = false;
                }
            } else {
                arr[--k] += str[i];
                if(k == 0) {
                    isForward = true;
                }
            }
        }
        string res = "";
        for(auto &s: arr) {
            res += s;
        }
        return res;
    }
};