class Solution {
private:
    int count_ways(int idx, int target, vector<vector<int>>& dp, vector<int>& coins){
        if(idx == 0){
            if(target % coins[idx] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int not_take = count_ways(idx-1, target, dp, coins);
        int take = 0;
        if(coins[idx] <= target){
            take = count_ways(idx, target - coins[idx], dp, coins);
        }
        return dp[idx][target] = take + not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long> (amount + 1, 0));
        for(int i = 0;i <= amount;i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j <= amount;j++){
                long not_take = dp[i-1][j];
                long take = 0;
                if(coins[i] <= j){
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = take + not_take;
            }
        }
        return dp[n - 1][amount];
    }
};