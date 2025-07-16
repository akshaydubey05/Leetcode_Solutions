class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1=nums[0], p2=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = max({nums[i], nums[i]*p1, nums[i]*p2});
            p2 = min({nums[i], nums[i]*p1, nums[i]*p2});
            p1=temp;
            maxi = max(maxi, p1);
        }
        return maxi;
    }
};