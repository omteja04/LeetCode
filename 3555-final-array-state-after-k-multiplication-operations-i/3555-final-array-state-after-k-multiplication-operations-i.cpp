
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0 ; i  < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while(k--) {
            auto [ele, ind] = pq.top();
            pq.pop();
            ele *= multiplier;
            pq.push({ele, ind});
        }
        vector<int>arr(nums.size());
        while(!pq.empty()) {
            auto [ele, ind] = pq.top();
            pq.pop();
            arr[ind] = ele;
        }
        return arr;

    }
};