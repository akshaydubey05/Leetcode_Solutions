class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt1 = 0, cnt2 = 0;
        int l1 = 0, l2 = 0;
        int ans1 = 0, ans2 = 0;

        // count subarrays with sum <= goal
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) cnt1++;
            while (cnt1 > goal) {
                if (nums[l1] == 1) cnt1--;
                l1++;
            }
            ans1 += (i - l1 + 1);
        }

        // if goal == 0 then atMost(goal - 1) = atMost(-1) = 0
        if (goal == 0) return ans1;

        // count subarrays with sum <= goal - 1
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) cnt2++;
            while (cnt2 > goal - 1) {
                if (nums[l2] == 1) cnt2--;
                l2++;
            }
            ans2 += (i - l2 + 1);
        }

        return ans1 - ans2;
    }
};
