class Solution {
private:
    int longest_seq(int idx1, int idx2, vector<vector<int>>& dp, string& text1, string& text2){
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + longest_seq(idx1-1, idx2-1, dp, text1, text2);
        }
        return dp[idx1][idx2] = max(longest_seq(idx1, idx2-1, dp, text1, text2), longest_seq(idx1-1, idx2, dp, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<=m;i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};