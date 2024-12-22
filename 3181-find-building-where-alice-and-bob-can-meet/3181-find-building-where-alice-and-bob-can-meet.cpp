class SegmentTree {
    vector<int> tree;
public:
    SegmentTree(int n) {
        tree.resize(4 * n + 1, 0);
    }
    void build(int idx, int low, int high, vector<int> &arr) {
        if(low == high) {
            tree[idx] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    int query(int idx, int low, int high, int left, int right) {
        // no overlap

        if (high < left || low > right) {
            return -1;
        }

        // complete overlap

        if(left <= low && right >= high) {
            return tree[idx];
        }

        // Partial overlap
        int mid = low + (high - low) / 2;
        int l = query(2 * idx + 1, low, mid, left, right);
        int r = query(2 * idx + 2, mid + 1, high, left, right);
        return max(l, r);
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = heights.size();
        SegmentTree tree(n);
        tree.build(0, 0, n - 1, heights);
        vector<int> ans;
        for(int i = 0 ; i < q; i++) {
            int h1 = queries[i][0];
            int h2 = queries[i][1];

            if(h1 == h2 || heights[max(h1, h2)] > heights[min(h1, h2)]) {
                ans.push_back(max(h1, h2));
            } else {
                int maxHeight = max(heights[h1], heights[h2]);
                int low = max(h1, h2) + 1;
                int high = n - 1;
                int curr = -1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    int maxi = tree.query(0, 0, n - 1, low, mid);
                    if(maxi > maxHeight) {
                        curr = mid;
                        high = mid - 1;
                    } else{
                        low = mid + 1;
                    }
                }
                ans.push_back(curr);

            }
        }
        return ans;

    }
};