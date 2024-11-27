class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> m;

       
        for (int i = 0; i < n - 1; i++) {
            m[i].push_back(i + 1);
        }

        int row = queries.size();
        vector<int> answer;

        for (int i = 0; i < row; i++) {
           
            m[queries[i][0]].push_back(queries[i][1]);

      
            vector<int> dist(n, INT_MAX);
            dist[0] = 0; 

          
            queue<int> q;
            q.push(0);

            
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : m[node]) {
                   
                    if (dist[node] + 1 < dist[neighbor]) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }

            
            answer.push_back(dist[n - 1]);
        }

        return answer;
    }
};