class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            string temp = "";
            if (path[i] == '/')
                continue;
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == "." || temp.empty()) {
                continue;
            } else if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(temp);
            }
        }
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};