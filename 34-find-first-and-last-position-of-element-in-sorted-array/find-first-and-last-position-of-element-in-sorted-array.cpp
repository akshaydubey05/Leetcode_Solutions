class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int l=0, h=nums.size()-1, ansi = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]<t){
                l=mid+1;
            }
            else{
                ansi=mid;
                h=mid-1;
            }
        }
        l=0, h=nums.size()-1;
        int ansj = nums.size();
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]<=t){
                l=mid+1;
            }
            else{
                ansj=mid;
                h=mid-1;
            }
        }
        if (ansi == -1 || nums[ansi] != t)
            return {-1,-1};
        return {ansi, ansj-1};
    }
};