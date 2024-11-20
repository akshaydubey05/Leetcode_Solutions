class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, count = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) count++;
            
            while (count > k) {
                if (nums[left] == 0) count--;
                left++;
            }
            
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;
    }
};