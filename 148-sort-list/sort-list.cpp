/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> a;
        ListNode * curr= head;
        while(curr!=NULL){
            a.push_back(curr->val);
            curr=curr->next;
        }
        sort(a.begin(),a.end());
        curr=head;
        for(int i=0;i<a.size();i++){
            curr->val=a[i];
            curr=curr->next;
        }
        return head;
    }
};