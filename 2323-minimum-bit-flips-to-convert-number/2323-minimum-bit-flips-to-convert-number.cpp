class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(goal == start) return 0;


        /*
            1010   ---->      0111


        */
        int res = goal ^ start;
        int cnt = 0;
        while(res) {
            if(res & 1) {
                cnt++;
            }
            res >>= 1;
        }
        return cnt;

    }
};