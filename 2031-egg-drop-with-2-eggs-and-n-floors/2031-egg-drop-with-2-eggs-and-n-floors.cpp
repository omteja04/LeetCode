class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1 + sqrt(1 + 8 * n)) / 2.0);
    }
};