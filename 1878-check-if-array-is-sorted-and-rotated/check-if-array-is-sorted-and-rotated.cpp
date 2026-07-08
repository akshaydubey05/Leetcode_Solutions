class Solution {
public:
    bool check(vector<int>& nums) {
        bool fall = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                if(fall) return false;
                fall = true;
            }
        }
        if(nums[nums.size()-1] > nums[0]){
            if(fall) return false;
        }
        return true;
    }
};