class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode node=ListNode(0, head);
        unordered_map<int, ListNode*> mp;//or use map
        int prefix=0;
        for(ListNode* ptr=&node; ptr; ptr=ptr->next){
            prefix+=(ptr->val);
            mp[prefix]=ptr;
        }
        prefix=0;//reset
        for(ListNode* ptr=&node; ptr; ptr=ptr->next){
            prefix+=(ptr->val);
            ptr->next=mp[prefix]->next;
        }
        return node.next;
    }
};
