class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // unodered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int &i : nums) mp[i]++;
        int totalDup = 0;
        for(auto &it : mp) {
            if(it.second > 1) totalDup = totalDup + it.second - 1;
        }
        int opCnt = 0;
        while(totalDup > 0) {
            if(nums.size() >= 3) {
                nums = vector<int>(nums.begin() + 3, nums.end());
            } else{
                nums.clear();
            }
            mp.clear();
            for(int &i : nums) mp[i]++;

            totalDup = 0;
            for(auto &it : mp) {
                if(it.second > 1) totalDup = totalDup + it.second - 1;
            }
            opCnt++;
        }
        return opCnt;


    }
};