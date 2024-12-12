class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for(int i = 0; i < k; i++) {
            int gift = pq.top();
            pq.pop();
            sum = sum - gift + sqrt(gift);
            pq.push(sqrt(gift));
        }
        return sum;
    }
};