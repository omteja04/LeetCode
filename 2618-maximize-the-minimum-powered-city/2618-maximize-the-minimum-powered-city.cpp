using ll = long long;
class Solution {
public:
    bool func(vector<ll> &power, ll mid, ll k, int r) {
        int n = power.size() - 1;
        vector<ll>addedPowers(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                addedPowers[i] += addedPowers[i - 1];
            }
            ll powerCityHas = addedPowers[i] + power[i];
            if(powerCityHas < mid) {
                ll needed  = mid - powerCityHas;
                k -= needed;
                if(k < 0) break; 
                // Since we dont need at i - r putting stations at i + r give power to i so that max point is i + 2r
                int j = min(i + r + r, n - 1);
                addedPowers[i] += needed;
                addedPowers[j + 1] -= needed;
            }
        }   
        return k >= 0;
    } 
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<ll> power(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[left] += 1ll * stations[i];
            power[right + 1] -= 1ll * stations[i];
        }
        for (int i = 1; i < n; i++) {
            power[i] += power[i - 1];
        }
        ll low = 0;
        ll high = LLONG_MAX;
        ll ans = 0;
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            if(func(power, mid, k, r)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }


        return ans;
    }
};