//![Screenshot 2024-10-22 213609.png](https://assets.leetcode.com/users/images/355c96b4-8ffe-4361-9637-5f1da862b2b3_1729613238.0245335.png)
#include <queue>
#include <vector>
#include <functional>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<long long> levelSums;

        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSums.push_back(levelSum);
        }

        if (levelSums.size() < k) return -1;
        std::nth_element(levelSums.begin(), levelSums.end() - k, levelSums.end());
        return *(levelSums.end() - k);
    }
};