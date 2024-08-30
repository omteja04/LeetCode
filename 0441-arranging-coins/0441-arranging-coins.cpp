class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        while(l <= r) {
            long mid = l + ((r - l) >> 1);
            if(mid*(mid + 1) / 2 == n) {
                return (int) mid;
            } else if(n < mid*(mid + 1) / 2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int) r;
    }
};