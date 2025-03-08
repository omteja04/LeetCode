class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i = 0; i  < number.length(); i++) {
            if(number[i] == digit) {
                if(i + 1 < number.length() && number[i + 1] > digit) {
                    number.erase(i, 1);
                    return number;
                }
            }
        }
        for(int i = number.size(); i >= 0; i--) {
            if(number[i] == digit) {
                    number.erase(i, 1);
                    return number;
            }
        }
        return number;
    }
};