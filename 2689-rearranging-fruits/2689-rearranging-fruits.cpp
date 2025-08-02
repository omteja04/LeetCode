class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for(auto &it : basket1) freq[it]++;
        for(auto &it : basket2) freq[it]++;
        long long mini = LLONG_MAX;
        for(auto &[fruit, count] : freq) {
            if(count % 2 == 1) return -1;
            mini = min(mini, (long long)fruit);
        }
        unordered_map<int, int> b1freq;
        vector<long long> reqToSwap;
        for(auto &it : basket1) b1freq[it]++;
        for(auto &[fruit, count]: freq) {
            int leftOverOrReq = b1freq[fruit] - (count / 2);
            for(int i = 0; i < abs(leftOverOrReq); i++) reqToSwap.push_back(fruit);
        }
        sort(reqToSwap.begin(), reqToSwap.end());
        long long cost = 0;
        for(int i = 0; i  < reqToSwap.size() / 2; i++) {
            cost += min(reqToSwap[i], 2 * mini);
        }
        return cost;

    }
};