class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        vector<int> flag(1000, 0);
        for(int i = 0 ; i < digits.size(); i++) {
            if(digits[i] == 0) {
                continue;
            }
            for(int j = 0; j < digits.size(); j++) {
                if(i == j) continue;
                for(int k = 0; k < digits.size(); k++) {
                    if(i == k || j == k) continue;
                    if(digits[k] & 1) continue;
                    int num = 100 * digits[i] + 10 * digits[j] + digits[k];
                    if(!flag[num]) {
                        flag[num] = true;
                        res.push_back(num);
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};