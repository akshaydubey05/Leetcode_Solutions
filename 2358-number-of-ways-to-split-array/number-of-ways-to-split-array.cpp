class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int ans = 0;
        long long int tsum = 0;
        long long int left = 0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            long long int right = tsum-left;
            if(left>=right){
                ans++;
            }
        }
        return ans;
    }
};