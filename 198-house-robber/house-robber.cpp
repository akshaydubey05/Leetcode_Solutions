class Solution {
public:

    int solve(vector<int>& nums,vector<int>& dp,int n){
        if(n==0){
            return nums[0];
        }
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int inc=dp[i-2]+nums[i];
            int exc=dp[i-1];
            dp[i]=max(inc,exc);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int x=solve(nums,dp,n-1);
        return x;
    }
};