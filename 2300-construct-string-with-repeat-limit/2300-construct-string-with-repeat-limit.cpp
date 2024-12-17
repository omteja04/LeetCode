class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }
        
        priority_queue<pair<char, int>> pq;
        for(auto &it : freq) {
            pq.push({it.first, it.second});
        }
        string ans;
        while(!pq.empty()) {
            auto [ele, cnt] = pq.top();
            pq.pop();
            int use = min(cnt, repeatLimit);
            ans.append(use, ele);
            cnt -= use;
            if(cnt > 0) {
                if(!pq.empty()) {
                    // sele = second element
                    // scnt = second cnt
                    auto [sele, scnt] = pq.top();
                    pq.pop();
                    ans.push_back(sele);
                    scnt--;
                    if(scnt > 0)
                        pq.push({sele, scnt});
                }
                else
                    break;
                pq.push({ele, cnt});
            }
        }
        return ans;




    }
};