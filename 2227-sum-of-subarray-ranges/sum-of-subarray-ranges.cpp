class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long int  ans=0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            long long mini = INT_MAX;
            long long maxi = INT_MIN;
            for (int j = i; j < n; j++) {
                mini = min(mini, (long long)nums[j]);
                maxi = max(maxi, (long long)nums[j]);
                ans += maxi - mini;
            }
        }
        return ans;
    }
};