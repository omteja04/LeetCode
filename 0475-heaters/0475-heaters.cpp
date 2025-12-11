class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for(auto &h : houses) {
            int idx = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();
            int dist = INT_MAX;
            if(idx < heaters.size()) {
                dist = min(dist, abs(heaters[idx] - h));
            }
            if(idx - 1 >= 0) {
                dist = min(dist, abs(heaters[idx - 1] - h));
            }
            radius = max(dist, radius);
        }
        return radius;
    }
};