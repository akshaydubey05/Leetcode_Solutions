class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

         if (k == 1) {
            return nums;
        }

        vector<int> res;
        int i=0,j=k-1;
        int f;
        while(j < nums.size()){

            bool isTrue = true;
            for(f=i;f<j;f++){
                if(nums[f] + 1 != nums[f + 1]){
               
                isTrue = false;
                    break;
                }
                    
            }
            if(isTrue)
                res.push_back(nums[j]);
            else
                res.push_back(-1);

            i++;
            j++;
        }
    return res;
    } 

};