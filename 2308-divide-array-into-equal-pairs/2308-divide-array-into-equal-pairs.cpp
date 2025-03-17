class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            x1 ^= nums[i];
            x2 ^= nums[i] + 1;
        }
        return x1 == 0 && x2 == 0;
    }
};