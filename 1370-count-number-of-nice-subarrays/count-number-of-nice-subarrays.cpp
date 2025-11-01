class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                cnt++;
            }
            while(cnt>k){
                if(nums[l]%2!=0){
                    cnt--;
                }
                l++;
            }
            ans+=i-l+1;
        }
        if(k==0){
            return ans;
        }
        int l1=0,cnt1=0,ans1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                cnt1++;
            }
            while(cnt1>k-1){
                if(nums[l1]%2!=0){
                    cnt1--;
                }
                l1++;
            }
            ans1+=i-l1+1;
        }
        return ans-ans1;
    }
};