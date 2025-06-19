class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int cnt = 0;
        // int i = 0;
        // while (i < nums.size()) {
        //     i = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
        //     cnt++;
        // }
        // return cnt;
        bitset<100001> exists;
        int mini = nums[0];
        int maxi = nums[0];
        for(auto &ele: nums) {
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            exists[ele] = true;
        }
        int start = mini;
        int cnt = 1;
        for(int ele = start; ele <= maxi; ele++) {
            if(exists[ele]) {
                if(ele - start > k) {
                    cnt++;
                    start = ele;
                }
            }
        }
        return cnt;

        
    }
};