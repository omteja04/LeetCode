class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";
        while(pq.size() > 1) {
            int freq1 = pq.top().first;
            char ch1 = pq.top().second;
            pq.pop();

            if(res.size() <= 1) {
                res += ch1;
                freq1--;
            } else {
                if(res[res.size() - 1] == ch1 && res[res.size() - 2] == ch1) {
                    int freq2 = pq.top().first;
                    int ch2 = pq.top().second;
                    pq.pop();
                    res += ch2;
                    freq2--;
                    if(freq2 > 0) pq.push({freq2, ch2});
                } else {
                    res += ch1;
                    freq1--;
                }
            }
            if(freq1 > 0) pq.push({freq1, ch1});
        }
        if(pq.size() == 1) {
            int freq1 = pq.top().first;
            int ch1 = pq.top().second;
            if(freq1 <= 1) {
                res += ch1;
            } else {
                res += ch1;
                res += ch1;
            }
        }
        return res;















        return res;

    }
};