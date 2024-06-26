#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    using int2 = pair<int, int>;
    vector<int2> bucket[1024];

    constexpr void radix_sort(vector<int2>& nums) {
        // 1st round
        for (auto& [x, i] : nums)
            bucket[x & 1023].emplace_back(x, i);
        int index = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[index++] = v;
            B.clear();
        }
        // 2nd round
        for (auto& [x, i] : nums)
            bucket[(x >> 10) & 1023].emplace_back(x, i);
        index = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[index++] = v;
        //    B.clear();
        }
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<int2> sIdx(n);
        for (int i = 0; i < n; i++)
            sIdx[i] = {score[i], i};
        radix_sort(sIdx);
        vector<string> ans(n);
        ans[sIdx[n - 1].second] = "Gold Medal";
        if (n > 1)
            ans[sIdx[n - 2].second] = "Silver Medal";
        if (n > 2)
            ans[sIdx[n - 3].second] = "Bronze Medal";
        for (int i = n - 4; i >= 0; i--)
            ans[sIdx[i].second] = to_string(n - i);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();