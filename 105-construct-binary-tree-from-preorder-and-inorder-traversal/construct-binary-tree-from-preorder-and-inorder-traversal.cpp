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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,n-1,inorder,0,n-1,mp);
    }
    TreeNode* solve(vector<int>& preorder, int ps, int pe, 
                    vector<int>& inorder, int is, int ie, 
                    unordered_map<int,int> &mp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        int root= preorder[ps];
        int pos=mp[root];
        int left=pos-is;
        TreeNode* rootans = new TreeNode(root);
        rootans->left = solve(preorder, ps+1, ps+left, inorder, is, pos-1, mp);
        rootans->right = solve(preorder, ps+left+1, pe, inorder, pos+1, ie, mp);
        
        return rootans;

    }
};