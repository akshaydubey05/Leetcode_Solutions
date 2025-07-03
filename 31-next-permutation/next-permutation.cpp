class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                x=i;
                break;
            }
        }
        if(x == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int mini = INT_MAX, z=-1;
            for(int i=x+1;i<n;i++){
                if(mini>=nums[i] && nums[i]>nums[x]){
                    mini = nums[i];
                    z=i;
                }
            }
            swap(nums[z], nums[x]);
            cout<<x<<" "<<z<<endl;
            for(auto i:nums){
                cout<<i<< " ";
            }
            reverse(nums.begin()+x+1, nums.end());
        }

    }
};