#include <vector>
#include <iostream>

using namespace std;

class SegmentTree {
public:
    vector<int> segmentTree;
    SegmentTree(int n) { segmentTree.resize(4 * n); }

    void build(vector<int>& arr, int node, int left, int right) {
        if (left == right) {
            segmentTree[node] = arr[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(arr, 2 * node, left, mid);
        build(arr, 2 * node + 1, mid + 1, right);
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }

    void update(int node, int left, int right, int pos, int val) {
        if (left == right) {
            segmentTree[node] += val;
            return;
        }
        int mid = left + (right - left) / 2;
        if (pos <= mid) {
            update(2 * node, left, mid, pos, val);
        } else {
            update(2 * node + 1, mid + 1, right, pos, val);
        }
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }

    int query(int node, int left, int right, int qs, int qe) {
        if (right < qs || left > qe)
            return 0;
        if (left >= qs && right <= qe)
            return segmentTree[node];
        int mid = left + (right - left) / 2;
        int leftSide = query(2 * node, left, mid, qs, qe);
        int rightSide = query(2 * node + 1, mid + 1, right, qs, qe);
        return leftSide + rightSide;
    }
};

class Solution {
public:
    const int N = 20001;  // This is the range for freq array
    int maxPos = 10000;  // Shift to handle negative numbers

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> freq(N, 0);
        for (int num : nums) {
            freq[num + maxPos]++;
        }
        SegmentTree tree(N);
        tree.build(freq, 1, 0, N - 1);
        vector<int> cnt;
        for (int num : nums) {
            freq[num + maxPos]--;
            tree.update(1, 0, N - 1, num + maxPos, -1);
            cnt.push_back(tree.query(1, 0, N - 1, 0, num + maxPos - 1));
        }
        return cnt;
    }
};
