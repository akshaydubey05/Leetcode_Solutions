class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        int l=0;
        int sum=0;
        int ans=0;
        unordered_map<int,int> pre;
        pre[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if (pre.count(sum - goal)) {
                ans += pre[sum - goal];
            }
            pre[sum]++;
        }
        cout<<sum<<endl;
        return ans;
    }
};