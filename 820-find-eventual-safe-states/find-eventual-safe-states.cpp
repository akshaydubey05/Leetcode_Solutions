class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                ind[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto x : adj[node]) {
                ind[x]--;
                if (ind[x] == 0)
                    q.push(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};