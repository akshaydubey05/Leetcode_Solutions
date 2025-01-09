class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int evenIndex = 0;
        int oddIndex = 1;
        for (int num : nums) {
            if (num % 2 == 0) { 
                ans[evenIndex] = num;
                evenIndex += 2;
            } else { 
                ans[oddIndex] = num;
                oddIndex += 2;
            }
        }
        return ans;
    }
};