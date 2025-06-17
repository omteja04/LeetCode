class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        for (auto& it : prerequisites) {
            inDegree[it[0]]++;
        }

        // for(int i : inDegree) {
        //     cout << i<< " ";
        // }

        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        vector<vector<int>> adj(numCourses);
        for (auto& it : prerequisites) {
            int v = it[0];
            int u = it[1];
            adj[u].emplace_back(v);
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto& neighbour : adj[front]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                    res.push_back(neighbour);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};