class Solution {
public:
    int solve(int n,vector<int> &cost,vector<int> &dp){
        if(n<=1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=cost[n]+min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        return dp[n];
    }
    int solve1(int n,vector<int> &cost,vector<int> &dp){
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);
        int x=solve1(n,cost,dp);
        return x;
    }

};