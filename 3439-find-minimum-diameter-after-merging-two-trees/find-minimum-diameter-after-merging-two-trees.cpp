class Solution {
public:
    pair<int, int> bfsTofindFarthestNode(int s, int v, unordered_map<int, vector<int>>& adj) {
        vector<bool> vis(v, false);
        queue<int> q;
        q.push(s);
        vis[s] = true;  // Mark starting node as visited
        int level = 0, farthestNode = s;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int node = q.front();
                q.pop();
                farthestNode = node;

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = true;  // Mark neighbor as visited before enqueueing
                        q.push(it);
                    }
                }
            }
            if (!q.empty()) level++;
        }

        return {farthestNode, level};
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int v = edges.size() + 1;  // Number of nodes
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto oneEndNode = bfsTofindFarthestNode(0, v, adj);
        auto otherEndNode = bfsTofindFarthestNode(oneEndNode.first, v, adj);

        return otherEndNode.second;  // Diameter of the tree
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = treeDiameter(edges1);
        int dia2 = treeDiameter(edges2);

        int combinedDia = ceil(dia1 / 2.0) + ceil(dia2 / 2.0) + 1;

        return max({dia1, dia2, combinedDia});
    }
};