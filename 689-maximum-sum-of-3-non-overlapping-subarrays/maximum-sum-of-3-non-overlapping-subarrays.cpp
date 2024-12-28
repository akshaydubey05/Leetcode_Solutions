class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        // Dynamic programming state: [momentum][prefix_beg]
        // - :momentum: current subarray backwards index i.e.: 0 = rightmost 1 = middle 2 = leftmost
        // - :prefix_beg: of current prefix
        // Each state stores: {best_starting_index, maximum_sum}
        vector<vector<pair<int, int>>> dp(kMomentumCount,
                                          vector<pair<int, int>>(N, {-1, 0}));

        for (int i = N - 1, j = N - 1, window_sum = 0; ~i; --i) { // Sliding window approach [i..j]
            window_sum += nums[i];
            if (j - i >= k)
                window_sum -= nums[j--];

            // Base: momentum = 0
            if (i + 1 < N)
                dp[0][i] = dp[0][i + 1]; // Inherit previous best
            if (N - i >= k && dp[0][i].second <= window_sum) // Improve if using i-th is better
                dp[0][i] = {i, window_sum};

            for (int m = 1; m < kMomentumCount; ++m) {
                if (i + 1 < N)
                    dp[m][i] = dp[m][i + 1]; // Inherit
                if (N - i > k && dp[m - 1][i + k].first > -1 &&
                        dp[m][i].second <= window_sum + dp[m - 1][i + k].second) // Improve
                    dp[m][i] = {i, window_sum + dp[m - 1][i + k].second};
            }
        }

        vector<int> res;
        // Reconstruct: start with leftmost momentum and prefix [0..
        // move to the current best_prefix_beg + k
        for (int m = kMomentumCount - 1, beg = 0; ~m; beg = dp[m][beg].first + k, --m)
            res.push_back(dp[m][beg].first);
        return res;
    }

private:
    static constexpr int kMomentumCount = 3;
};