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
public:

    void f(TreeNode* root, unordered_map<int, int> &mp, int l){

        if(root == NULL) return;

        if(mp.find(l) == mp.end()) mp[l] = root->val;
        else mp[l] = max(mp[l], root->val);
        f(root->left, mp, l+1);
        f(root->right, mp, l+1);

        return;
    }
    vector<int> largestValues(TreeNode* root) {
        
        unordered_map<int, int> mp;
        f(root, mp, 0);

        vector<int> ans(mp.size());
        for(auto x: mp)
            ans[x.first] = x.second;
        
        return ans;
    }
};