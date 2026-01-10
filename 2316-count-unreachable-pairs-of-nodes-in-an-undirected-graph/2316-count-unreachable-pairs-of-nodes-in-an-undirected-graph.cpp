class DSU {
public:
    vector<long long> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if(size[u] > size[v]) {
            parent[v] = u;
            size[u] += size[v];
        } else {
            parent[u] = v;
            size[v] += size[u];
        }
    }
};


class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto &edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }
        unordered_map<int, long long> compSize;
        for (int i = 0; i < n; i++) {
            compSize[dsu.find(i)]++;
        }
        long long res = 0;
        long long sum = 0;
        for(auto &kv : compSize) {
            long long size = kv.second;
            res += size * sum;
            sum += size;
        }
        return res;
    }
};