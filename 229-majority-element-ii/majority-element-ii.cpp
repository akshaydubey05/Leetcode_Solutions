class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0, c2=0, e1=INT_MIN, e2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(c1 == 0 && e2!=nums[i]){
                c1++;
                e1=nums[i];
            }
            else if(c2 == 0 && e1!=nums[i]){
                c2++;
                e2=nums[i];
            }
            else if(e1 == nums[i]){
                c1++;
            }
            else if(e2 == nums[i]){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
            vector<int> ss;
            for(int i=0;i<nums.size();i++){
                if(nums[i] == e1){
                    c1++;
                }
                if(nums[i] == e2){
                    c2++;
                }
            }
            vector<int> ans;
            if(c1 >(nums.size()/3)){
                ans.push_back(e1);
            }
            if(c2 >(nums.size()/3)){
                ans.push_back(e2);
            }
            return ans;
    }
};