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
    string tree2str(TreeNode* root) {
        string ch="";
        check(root,ch);
        return ch;
    }
    void check(TreeNode* root,string &ch){
        if(root==NULL){
            return;
        }
        ch=ch+to_string(root->val);
        if(root->left || root->right){
            ch+='(';
            check(root->left,ch);
            ch+=')';
        }
        if(root->right){
            ch+='(';
            check(root->right,ch);
            ch+=')';
        }
    }
};