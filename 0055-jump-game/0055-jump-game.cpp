class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = nums[0];
        for (int i=0; i<n; i++){
            if (i <= maxReach){
                maxReach = max(maxReach, i+nums[i]);
            }
            else return false;
        }
        return true;
    }
};