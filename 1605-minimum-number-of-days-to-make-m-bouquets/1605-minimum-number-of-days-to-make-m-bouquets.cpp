class Solution {
    bool can(vector<int> & bloomDay, int mid, int m, int k) {
        int flowers = 0;
        int boquetCnt = 0;
        for(int i = 0; i  < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                flowers++;
                if(flowers == k) {
                    flowers = 0;
                    boquetCnt++;
                    if(boquetCnt == m) {
                        return 1;
                    }
                }
            }
            else {
                flowers = 0;
            }
        }
        return 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long long) m * k) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(can(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;

    }
};