class Solution {
private:
    int binary(vector<int>& nums, int l, int h, int t){
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid] == t){
                return mid;
            }
            else if(nums[mid]<=t){
                l=mid+1;
            }
            else{
                h=mid-1;
            }

        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int x = binary(nums, 0, nums.size()-1, target);
        return x;
    }
};