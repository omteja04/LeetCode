class Solution {
public:
    int sumOfTheString(string s) {
        int sum = 0;
        for(auto &ch : s) {
            sum += (ch - '0');
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string ss = "";
        for(char &ch : s) {
            int n = ch - 'a' + 1;

            // cout<<c<<" ";
            ss += to_string(n);
        }
        // cout<<endl;
        int obtainedNum;
        while(k--) {
            // cout<<ss<<endl;
            obtainedNum = sumOfTheString(ss);
            ss =  to_string(obtainedNum);
        }
        return obtainedNum;

        
    }
};