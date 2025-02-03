class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int inc=1;
            int dec=1;
            int curr=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>curr)
                {
                    inc++;
                    curr=nums[j];
                }
                else
                {
                    break;
                }
            }
            curr=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]<curr)
                {
                    dec++;
                    curr=nums[j];
                }
                else
                {
                    break;
                }
            }
            int temp=max(dec,inc);
            ans=max(ans,temp);
        }
        return ans;
    }
};