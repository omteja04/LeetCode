import java.util.*;
class Solution {
    public static void rec(int node, ArrayList<ArrayList<Integer>> adj, boolean vis[]) {
        // dfs.add(node);
        vis[node] = true;
        for(Integer num : adj.get(node)) {
            if(!vis[num]) {
                rec(num, adj, vis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int cnt = 0;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int n = isConnected.length;
        for(int i = 0; i < n; i ++) {
            graph.add(new ArrayList<>());
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0;  j < n; j++) {
                // if(i == j) continue;
                if(isConnected[i][j] == 1) {
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
            }
        }
        boolean[] vis = new boolean[n];
        for(int i = 0 ; i < n; i ++) {
            if(vis[i] == false) {
                cnt++;
                rec(i, graph, vis);
            }
        }
        return cnt;
    }
}