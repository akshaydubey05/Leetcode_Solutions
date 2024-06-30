class Solution {
public:
    int solve(vector<int> &coins, vector<int> &dp,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            dp[amount]=solve(coins,dp,amount-coins[i]);
            if(dp[amount]!=INT_MAX){
                mini=min(mini,1+dp[amount]);
            }
        }
        dp[amount]=mini;
        return dp[amount];
    }
    int solvetab(vector<int> &coins,vector<int> &dp, int amount){
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount];
    }
    int solverec(vector<int> &coins, int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solverec(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,ans);
            }
        }
        return mini;
    }


    int coinChange(vector<int>& coins, int amount) {
       // int n=coins.size();
        //int x=solverec(coins,amount);
        /* if(x==INT_MAX){
            return -1;
        }
        return x; */


        /* vector<int> dp(amount+1,-1);
        int y=solve(coins,dp,amount);
        if(y==INT_MAX){
            return -1;
        }
        return y; */

        vector<int> dp(amount+1,INT_MAX);
        int x=solvetab(coins,dp,amount);
        if(x==INT_MAX){
            return -1;
        }
        return x;
    }
};