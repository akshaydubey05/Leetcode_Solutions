
class Solution {
public:
    int solve(int ans,int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            ans++;
            return dp[n];
        }
        dp[n]=solve(ans,n-1,dp)+solve(ans,n-2,dp);
        ans++;
        return dp[n];
    }
    int climbStairs(int n) {
        n++;
        vector<int> dp(n+1,-1);
        int ans=0;
        return solve(ans,n,dp);
    }
};

