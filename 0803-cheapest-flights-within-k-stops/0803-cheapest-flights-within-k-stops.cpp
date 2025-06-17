class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while (!q.empty() && stops <= k) {
            int size = q.size();
            while (size--) {
                auto [currentNode, price] = q.front();
                q.pop();
                for (auto& [neighbourNode, nPrice] : adj[currentNode]) {
                    if (nPrice + price < minCost[neighbourNode]) {
                        minCost[neighbourNode] = nPrice + price;
                        q.push({neighbourNode, minCost[neighbourNode]});
                    }
                }
            }
            stops++;
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
