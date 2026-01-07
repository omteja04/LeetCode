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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        map<int, vector<int>> value2Nodes;
        for (int i = 0; i < n; i++) {
            value2Nodes[vals[i]].push_back(i);
        }
        for(auto &edge : edges) {
            int a = edge[0], b = edge[1];
            if(vals[a] >= vals[b]) {
                adj[a].push_back(b);
            }
            if(vals[b] >= vals[a]) {
                adj[b].push_back(a);
            }
        }
        DisjointSet dsu(n);
        int res = 0;
        for(auto &ele : value2Nodes) {
            int value = ele.first;
            for(auto &node : ele.second) {
                for(auto &neigh : adj[node]) {
                    dsu.unionBySize(node, neigh);
                }
            }
            unordered_map<int, int> componentValueCount;
            for(auto &node : ele.second) {
                componentValueCount[dsu.findParent(node)]++;
            }
            res += ele.second.size();
            for(auto &[componentId, cnt] : componentValueCount) {
                if(cnt > 1) {
                    res += (cnt * (cnt - 1)) / 2;
                }
            }
        }
        return res;

    }
};