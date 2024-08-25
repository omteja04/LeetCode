class Solution {
public:
    vector<int> lp;
    vector<int> pr;
    int countPrimes(int n) {
        lp.resize(n + 1, 0);
        for(int i = 2; i < n; i++ ) {
            if(lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for(int j = 0; pr[j] * i < n; j++) {
                lp[pr[j] * i] = lp[i];
                if(lp[i] == pr[j]) break;
            }
        }
        return pr.size();
    }
};