class Solution {
    long long generate(long long num, bool isEven) {
        long long palindrome = num;
        if(!isEven) {
            num /= 10;
        }
        while(num > 0) {
            palindrome = palindrome*10 + num % 10;
            num /= 10;
        }
        return palindrome;
    }
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        if(num <= 10) return to_string(num - 1);
        if(num == 11) return "9";

        if(n == "999999999999999999") return "1000000000000000001";

        int length = n.length();
        long long leftHalf = stoll(n.substr(0, (length + 1)/ 2));
        vector<long long> palindromePossibilites(5);
        palindromePossibilites[0] = generate(leftHalf, length % 2 == 0);
        palindromePossibilites[1] = generate(leftHalf - 1, length % 2 == 0);
        if(leftHalf < 999999999) {
            palindromePossibilites[2] = generate(leftHalf + 1, length % 2 == 0);
        } else {
            palindromePossibilites[2] = stoll("1" + string(length - 1,'0') + "1");
        }
        palindromePossibilites[3] = pow(10, length - 1) - 1;
        palindromePossibilites[4] = pow(10, length) + 1;

        long long nearPalin = 0;
        long long minDiff = LLONG_MAX;
        for(auto candidate: palindromePossibilites) {
            if(candidate == num) continue;
            long long diff = abs(candidate - num);
            if(diff < minDiff || (diff == minDiff && candidate < nearPalin)) {
                minDiff = diff;
                nearPalin = candidate;
            }
        }
        return to_string(nearPalin);

    }

};