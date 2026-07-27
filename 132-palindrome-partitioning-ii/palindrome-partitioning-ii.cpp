class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }

        // isPal[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) {
                        isPal[i][j] = true;
                    } else {
                        isPal[i][j] = isPal[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] stores the minimum cuts needed for prefix s[0...i]
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // Maximum cuts possible
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};