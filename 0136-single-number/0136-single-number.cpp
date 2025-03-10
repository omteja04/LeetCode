class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int value = 0
        // Iterate over the array =>
        // value  = value ^ nums[i]
        // return value
        int value = 0;
        for(int i = 0; i < nums.size(); i++) {
            value = value ^ nums[i];
        }
        return value;
        

        // If any doubts, ASK Mr. Karthik
    }
};