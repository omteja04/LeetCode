class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]) {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        } else {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges,
                                           vector<vector<int>>& queries) {
        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });
        
        vector<bool> ans(queries.size());

        DisjointSet dsu(n);
        int edgeInd = 0;
        for(auto &query : queries) {
            int u = query[0], v = query[1], limit = query[2], ind = query[3];
            while(edgeInd < edges.size() && edges[edgeInd][2] < limit) {
                dsu.unionBySize(edges[edgeInd][0], edges[edgeInd][1]);
                edgeInd++;
            }
            ans[ind] = dsu.findParent(u) == dsu.findParent(v);
        }
        return ans;
    }
};