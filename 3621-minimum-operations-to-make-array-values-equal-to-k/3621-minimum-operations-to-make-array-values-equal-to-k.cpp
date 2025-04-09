class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for(auto &it: nums) {
            st.insert(it);
        }
        if(*st.begin() < k) {
            return -1;
        }
        if(*st.begin() == k) {
            return st.size() - 1;
        } 
        return st.size();
    }
};