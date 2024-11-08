class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = (1<<maximumBit) - 1;
        vector<int> ans(nums.size());
        int curr = 0;
        for(int i=0;i<nums.size();i++){
            curr = curr ^ nums[i];
            ans[nums.size()-i-1] = maxi - curr;
        }
        return ans;
    }
};