class Solution {
public:
    bool check(vector<vector<int>>& graph, int i, vector<int>& color) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto& node : graph[x]) {
                if (color[node] == -1) {
                    color[node] = 1 - color[x];
                    q.push(node);
                } else if (color[node] == color[x]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!check(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};