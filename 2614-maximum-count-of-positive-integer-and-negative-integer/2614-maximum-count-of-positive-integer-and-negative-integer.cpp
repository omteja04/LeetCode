class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        cout <<neg <<" "<<pos;
        neg = neg;
        pos = n - pos;

        return max(neg, pos);
    }
};