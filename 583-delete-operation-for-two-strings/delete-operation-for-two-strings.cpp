class Solution {
private:
    int longestPalindrome(int idx1, int idx2, string& s1, string& s2, vector<vector<int>>& dp){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(s1[idx1] == s2[idx2]){
            return dp[idx1][idx2] = 1 + longestPalindrome(idx1-1, idx2-1, s1, s2, dp);
        }
        return dp[idx1][idx2] = max(longestPalindrome(idx1, idx2-1, s1, s2, dp), longestPalindrome(idx1-1, idx2, s1, s2, dp));
    }
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int> (m+1, -1));
        int max_length = longestPalindrome(n-1, m-1, s1, s2, dp);
        return n + m - 2*max_length;
    }
};