class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size(), c = points[0].size();
        vector<vector<long long int>> dp(r, vector<long long int>(c));

        for (int j = 0; j < c; j ++) {
            dp[0][j] = points[0][j];
        }
        for (int i = 1; i < r; i ++) {

            long long int maxValue = 0;

            for (int j = 0; j < c; j ++) {
                
                maxValue = max(maxValue - 1, dp[i - 1][j]);
                dp[i][j] = maxValue + points[i][j];

            }

            maxValue = 0;
            for (int j = c - 1; j >= 0; j --) {
                maxValue = max(maxValue - 1, dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], maxValue + points[i][j]);
            }

        }

        long long int ans = 0;
        for (int j = 0; j < c; j ++) {
            ans = max(ans, dp[r - 1][j]);
        }

        return ans;
    }
};