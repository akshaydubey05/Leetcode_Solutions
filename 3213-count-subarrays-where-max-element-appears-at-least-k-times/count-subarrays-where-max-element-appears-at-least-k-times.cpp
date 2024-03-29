class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int mx=*max_element(begin(nums),end(nums));
        long long ans=0;
        
        int l=0,r=0,n=size(nums);
        while(r<n){
            k-=(nums[r++]==mx);
            while(k==0){
                k+=(nums[l++]==mx);
            }
            ans+=l;
        }
        return ans;
    }
};