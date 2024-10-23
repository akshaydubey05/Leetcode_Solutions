
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int current_lvl = 0;
        vector<TreeNode*>cousins;
        root->val = 0;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            if (f.second > current_lvl) {
                replace_cousins(cousins);
                while (cousins.size() > 0) cousins.pop_back();
                cousins.push_back(f.first);
                current_lvl = f.second;
            } else {
                cousins.push_back(f.first);
            }
            if (f.first->left != NULL) {
                q.push({f.first->left, f.second + 1});
            }
            if (f.first->right != NULL) {
                q.push({f.first->right, f.second + 1});
            }
        }
        return root;
    }
    void replace_cousins(vector<TreeNode*>& v) {
        int sumcousins = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i]->left != NULL) {
                sumcousins += v[i]->left->val;
            }
            if (v[i]->right != NULL) {
                sumcousins += v[i]->right->val;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int sameParent = 0;       
            if (v[i]->left != NULL) 
                sameParent += v[i]->left->val;
            if (v[i]-> right != NULL)
                sameParent += v[i]->right->val;
            //calculated before the sum of children with the same parent
            //now we update
            if (v[i]->left != NULL) {
                v[i]->left->val = sumcousins - sameParent;
            }
            if (v[i]->right != NULL) {
                v[i]->right->val = sumcousins - sameParent;
            }
            //cout << v[i]->val<<" "<< sumcousins<<" "<<sameParent<<endl;
        }
    }
};