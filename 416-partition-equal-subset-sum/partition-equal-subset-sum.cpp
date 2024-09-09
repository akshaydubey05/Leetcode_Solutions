class Solution {
private:
    bool find(int sum, int index, vector<vector<int>>& dp, vector<int>& nums){
        if(index == 0){
            return nums[index] == sum;
        }
        if(sum == 0){
            return true; 
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        
        bool not_taken = find(sum, index-1, dp, nums);
        bool taken = false;
        if(nums[index] <= sum){
            taken = find(sum - nums[index], index-1, dp, nums);
        }
        return dp[index][sum] = taken || not_taken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1, -1));
        bool ans = find(sum/2, nums.size()-1, dp, nums);
        return ans;

    }
};