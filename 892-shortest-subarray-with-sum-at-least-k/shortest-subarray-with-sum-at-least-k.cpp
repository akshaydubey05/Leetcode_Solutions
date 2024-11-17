class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for(int i = 0; i < n; ++i){
            pre[i + 1] = pre[i] + nums[i];
        }
        deque<int> dq;

        int ans = n + 1;
        for(int right = 0; right <= n; ++right){
            while(!dq.empty() && pre[right] <= pre[dq.back()]){
                dq.pop_back();
            }
            while(!dq.empty() && pre[right] - pre[dq.front()] >= k){
                ans = min(ans, right - dq.front());
                dq.pop_front();
            }
            dq.push_back(right);
        }
        return ans == n + 1 ? -1 : ans;
    }
};