class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 0 ;i  < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int cnt = 0;
        for(int i = 1; i  < n; i++) {
            if(prefix[i] >= prefix[n] - prefix[i]) cnt++;
        }
        return cnt;
    }
};