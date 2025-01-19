
class Solution {
public:
    int trapRainWater1(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0;
        }

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        // Add all boundary cells to the min-heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;
        int currentMaxHeight = 0;

        while (!minHeap.empty()) {
            auto [height, pos] = minHeap.top();
            minHeap.pop();
            currentMaxHeight = max(currentMaxHeight, height);

            for (const auto& dir : directions) {
                int nx = pos.first + dir.first;
                int ny = pos.second + dir.second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Calculate the water that can be trapped
                    if (heightMap[nx][ny] < currentMaxHeight) {
                        waterTrapped += currentMaxHeight - heightMap[nx][ny];
                    }
                    // Push the neighbor into the heap with the max height
                    minHeap.push({max(heightMap[nx][ny], currentMaxHeight), {nx, ny}});
                }
            }
        }

        return waterTrapped;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        return trapRainWater1(heightMap);
    }
};