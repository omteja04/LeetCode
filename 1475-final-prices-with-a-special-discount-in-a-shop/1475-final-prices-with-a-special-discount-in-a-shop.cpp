class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = prices;
        stack<int> st;
        for(int i = 0; i < prices.size(); i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                res[st.top()] = prices[st.top()] - prices[i];
                st.pop(); 
            }
            st.push(i);
        }
        // while(!st.empty()) {
        //     res[st.top()] = prices[st.top()];
        //     st.pop();
        // }
        return res;
    }
};