class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        // vector<pair<int, pair<int, int>>> events;
        // for(int i = 0; i < startTime.size(); i++) {
        //     events.push_back({endTime[i] - startTime[i], {startTime[i], endTime[i]}});
        // }
        // int maxFreeTime = startTime[0] - 0;
        // pair<int, int> maxFreeTimeStart = {0, -1};
        // int maxFreeTimeEnd = {startTime[0], 0};
        // for(int i = 0;i < n - 1; i++) {
        //     int diff = startTime[i + 1] - endTime[i];
        //     if(diff > maxFreeTime) {
        //         maxFreeTime = diff;
        //         maxFreeTimeStart = {endTime[i], i};
        //         maxFreeTimeEnd = {startTime[i + 1], i + 1};
        //     }
        // }
        // int way1 = maxTimeStart.second;
        // int way2 = maxTimeEnd.second;
        // int kk = k;
        // for(int i = way1; i>= 0; i--) {
            
        // }
        vector<int> gaps;
        
        gaps.push_back(startTime[0] - 0);
        // cout << gaps[0]<<" ";
        for(int  i = 0; i < n - 1; i++) {
            gaps.push_back(startTime[i + 1] - endTime[i]);
            // cout << gaps[i + 1] <<" ";
        }
        gaps.push_back(eventTime - endTime[n - 1]);
        
        // cout << gaps[gaps.size() - 1];
        int sum = 0;
        int maxi = 0;
        for(int left = 0, right = 0; right < gaps.size(); right++) {
            sum += gaps[right];

            if(right >= k + 1) {
                sum -= gaps[left];
                left++;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
        
    }
};