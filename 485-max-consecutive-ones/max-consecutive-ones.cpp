class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0,max = 0,dyn = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                j = i;
                break;
            }
        }
        for(int i = j;i<nums.size();i++){
            if(nums[i] == 1){
                dyn++;
                if(max < dyn){
                    max = dyn;
                }
            }
            else{
                dyn = 0;
            }
        }
        return max;
    }
};