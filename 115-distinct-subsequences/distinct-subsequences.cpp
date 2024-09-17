class Solution {
private:
    int distinctSeq(int idx1, int idx2, string& s1, string&s2, vector<vector<int>>& dp){
        if(idx2 < 0){
            return 1;
        }
        if(idx1 < 0){
            return 0;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        int result = 0;
        if(s1[idx1] == s2[idx2]){
            int next = distinctSeq(idx1-1, idx2-1, s1, s2, dp);
            int same = distinctSeq(idx1-1, idx2, s1, s2, dp);
            result = (same + next);
        }
        else{
            result = distinctSeq(idx1-1, idx2, s1, s2, dp);
        }
        return dp[idx1][idx2] = result;
        
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return distinctSeq(n-1, m-1, s, t, dp);
    }
};