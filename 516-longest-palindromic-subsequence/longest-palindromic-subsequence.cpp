class Solution {
private:
    int maxPalimdrome(int idx1, int idx2, vector<vector<int>>& dp, string s1, string s2){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(s1[idx1] == s2[idx2]){
            return 1 + maxPalimdrome(idx1 - 1, idx2 - 1, dp, s1, s2);
        }
        return max(maxPalimdrome(idx1 - 1, idx2, dp, s1, s2), maxPalimdrome(idx1, idx2 - 1, dp, s1, s2));
    }
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        int ans = 0;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return ans;
    }
};