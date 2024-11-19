class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int
         sum = 0, maxi = 0;
        long long int l=0, i=0;
        map<long long int,long long int> mp;
        for(int i = 0; i < nums.size(); i++){
            sum +=  nums[i];
            mp[nums[i]]++;
            if(i-l+1 == k){
                if(mp.size() == i-l+1){
                    maxi = max(maxi, sum);
                }
                sum = sum - nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return maxi;
    }
};