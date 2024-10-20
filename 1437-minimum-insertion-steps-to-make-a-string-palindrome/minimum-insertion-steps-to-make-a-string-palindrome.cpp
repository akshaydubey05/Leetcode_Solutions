class Solution {
public:
    int minInsertions(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n-ans;
    }
};