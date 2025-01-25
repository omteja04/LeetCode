class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> vec = {-100001, 100001};
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int lists = nums.size();
        set<tuple<int, int, int>> st; // <value, i, j>
        for(int i = 0; i < lists; i++) {
            st.insert(make_tuple(nums[i][0], i, 0));
        }
        while(1) {
            // bool completed = false;
            auto minTuple = *st.begin();
            auto maxTuple = *st.rbegin();
            maxi = get<0>(maxTuple);
            mini = get<0>(minTuple);
            if(vec[1] - vec[0] > (long long)maxi - mini) {
                vec[1] = maxi;
                vec[0] = mini;
            }
            st.erase(st.begin());

            int i = get<1>(minTuple);
            int j = get<2>(minTuple);
            if(j + 1 >= nums[i].size()) break;
            st.insert(make_tuple(nums[i][j + 1], i, j + 1));
        }
        return vec;





    }

};