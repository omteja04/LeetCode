class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalReq = 0;
        for(int ch : chalk) totalReq += ch;

        k%=totalReq;

        if(k == 0) return 0;
        int ind = 0;

        while(chalk[ind] <= k) {
            k -= chalk[ind];
            ind++;
        }
        return ind;
    }
};