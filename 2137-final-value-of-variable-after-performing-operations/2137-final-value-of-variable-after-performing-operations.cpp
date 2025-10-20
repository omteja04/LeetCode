class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string ch : operations) {
            if (ch[0] == '+' || ch[1] == '+') {
                X += 1;
            } else {
                X -= 1;
            }
        }
        return X;
    }
};