class Solution {
public:
    int n;
    int dp[1002][1002][4];
    int f(int ind, int prev, int k, vector<int> &rating) {
        if(k == 3) return 1;
        if(ind == n) {
            return 0;
        }
        if(dp[ind][prev+1][k] != -1) return dp[ind][prev+1][k];
        int nottake = f(ind+1, prev, k, rating);
        int take = 0;
        if(prev == -1 || rating[ind] > rating[prev]) {
            take = f(ind+1, ind, k+1, rating);
        }
        return dp[ind][prev+1][k] = take + nottake;
    }

    int numTeams(vector<int>& rating) {
        n = rating.size();
        int ans = 0;
        memset(dp, -1, sizeof dp);
        ans += f(0, -1, 0, rating);
        reverse(rating.begin(), rating.end());
        memset(dp, -1, sizeof dp);
        ans+= f(0, -1, 0, rating);
        return ans;
    }
};