class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passes, int total) {
            return (double) (passes + 1) / (total + 1) - (double) (passes) / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for(auto &currClass : classes) {
            maxHeap.push({calculateGain(currClass[0], currClass[1]), {currClass[0], currClass[1]}});
        }

        while(extraStudents--) {
            auto[currGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int pass = classInfo.first;
            int tot = classInfo.second;
            maxHeap.push({calculateGain(pass + 1, tot + 1), {pass + 1, tot + 1}});
        }
        double totalPassRatio = 0;

        while(!maxHeap.empty()) {
            auto[_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double) classInfo.first / classInfo.second;
        }
        return totalPassRatio / classes.size();

    }
};