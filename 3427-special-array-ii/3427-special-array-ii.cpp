class Solution {
    class SegmentTree {
        public:
            vector<int> tree;
            int n;
            SegmentTree(vector<int> &arr) {
                n = arr.size(); 
                tree.resize(4 * n, 1);
                build(0, 0, n - 1, arr);
            }
            void build(int node, int start, int end, vector<int> &arr) {
                if(start == end) {
                    tree[node] = 1;
                    return;
                }
                int mid = start + (end-  start) / 2;
                build(2 * node + 1, start, mid, arr);
                build(2 * node + 2, mid + 1, end, arr);

                tree[node] = tree[2 * node + 1] & tree[2 * node + 2];

                if((arr[mid] & 1) == (arr[mid + 1] & 1)) {
                    tree[node] = 0;
                }
            }
            int query(int node, int start, int end, int left, int right, vector<int> &arr) {
                if(start > right || end < left) {
                    return 1;
                }
                if(start >= left && end <= right) {
                    return tree[node];
                }
                int mid = start + (end - start) / 2;

                int leftQuery = query(2 * node + 1, start, mid, left, right, arr);
                int rightQuery = query(2 * node + 2, mid + 1, end, left, right, arr);
                int result = leftQuery & rightQuery;

                if (left <= mid && right > mid) {
                    if ((arr[mid] & 1) == (arr[mid + 1] & 1)) {
                        result = 0;
                    }
                }
                return result;
            }
            bool isSpecial(int left, int right, vector<int>& arr) {
                return query(0, 0, n - 1, left, right, arr);
            }
    };
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree st(nums);
        vector<bool> res;
        for(auto &query : queries) {
            res.push_back(st.isSpecial(query[0], query[1], nums));
        }
        return res;
    }
};