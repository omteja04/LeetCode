class Solution {
public:
    bool bipartite(vector<vector<int>>& adj, int n, int i, vector<int>& color) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int neighbour : adj[x]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - color[x];
                    q.push(neighbour);
                } else if (color[neighbour] == color[x]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, -1);

        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!bipartite(adj, n, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};