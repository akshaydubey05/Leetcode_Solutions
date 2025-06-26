class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> a;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                a.push_back(nums[i]);
            }
        }
        for(int i=0;i<count;i++){
            a.push_back(0);
        }
        nums=a;
    }
};