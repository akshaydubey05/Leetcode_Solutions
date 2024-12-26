class Solution {
private:
    int helper(int ind, int currSum, int target, vector<int> &nums,unordered_map<string,int>&dp) {
        if(ind >= nums.size()) {
            if(target == currSum)
                return 1;
            return 0;
        }
        string curr = to_string(ind)+"->"+to_string(currSum);
        if(dp.find(curr) != dp.end())
            return dp[curr];
        int plus =  helper(ind+1, currSum - nums[ind], target, nums, dp);
        int minus = helper(ind+1, currSum + nums[ind], target, nums, dp);
        return dp[curr] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>dp;
        return helper(0, 0, target, nums, dp);
    }
};