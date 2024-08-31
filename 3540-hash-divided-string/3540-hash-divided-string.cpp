class Solution {
public:
    string stringHash(string s, int k) {
        vector<string> vec;
        for(int i = 0; i < s.length() - k + 1; i += k) {
            string str = s.substr(i, k);
            vec.push_back(str);
        }
        // for(string i:vec){
        //     cout<<i<<endl;
        // }
        // return "";
        string res = "";
        for(auto &i : vec) {
            int sum = 0;
            for(int j = 0; j < k; j++) {
                sum += (i[j] - 'a');
            }
            sum %= 26;
            char ch = 'a' + sum;
            res += ch;

        }
        return res;

    }
};