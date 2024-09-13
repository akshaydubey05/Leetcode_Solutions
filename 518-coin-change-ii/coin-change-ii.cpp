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
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return count_ways(n-1, amount, dp, coins);
    }
};