class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> maxHeap;
        vector<int> res;

        for(auto &query : queries) {
            int x = query[0];
            int y = query[1];
            int distance = abs(x) + abs(y);
            if(maxHeap.size() < k) {
                maxHeap.push(distance);
            } else if(distance < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(distance);
            }

            if(maxHeap.size() < k) {
                res.push_back(-1);
            } else {
                res.push_back(maxHeap.top());
            }

        }
        return res;
    }
};