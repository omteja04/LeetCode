class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        // 00000000000101

        // 00000000000111
        // &
        // 11111111111010

        int m=num;
        while(m){
            mask = (mask<<1) | 1;
            m>>=1;
        }
        return mask&(~(num));



    }
};