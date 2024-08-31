/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    int max_sum_overall(TreeNode* node, int &max_sum){
        if(node == NULL){
            return 0;
        }
        int max_left_sum = max(0, max_sum_overall(node->left, max_sum));
        int max_right_sum = max(0, max_sum_overall(node->right, max_sum));
        max_sum = max(max_sum, max_left_sum + max_right_sum + node->val);
        return max(max_left_sum , max_right_sum) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        max_sum_overall(root, max_sum);
        return max_sum;
    }
};