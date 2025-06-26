class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int i=0;
        int cnt=0;
        int maxi = INT_MIN;
        while(i<nums.size()){
            if(nums[i]==1){
                cnt++;
                maxi=max(cnt,maxi);
            }
            else{
                cnt=0;
            }
            i++;
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};