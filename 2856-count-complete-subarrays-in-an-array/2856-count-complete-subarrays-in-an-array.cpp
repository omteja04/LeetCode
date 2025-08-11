class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        int left = 0, res = 0;
        unordered_map<int, int> mp;
        for(int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while(mp.size() == k) {
                res += (n - right);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
        }
        return res;

    }
};