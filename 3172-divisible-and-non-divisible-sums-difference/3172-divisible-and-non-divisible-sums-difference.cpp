class Solution {
public:
    int findSum(int n) {
        return n * (n + 1) / 2;
    }
    int differenceOfSums(int n, int m) {
        int totalSum = findSum(n);
        // m,2m,3m,4m,5m, ...
        // m(1,2,3,4,5...)
        int k = n / m;
        int divisibleSum = findSum(k);
        divisibleSum *= m;


        

        return totalSum - 2* divisibleSum;


    }
};