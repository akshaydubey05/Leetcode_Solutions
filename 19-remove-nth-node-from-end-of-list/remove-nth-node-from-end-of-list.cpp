class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        int x=0;
        while(curr!=NULL){
            x++;
            curr=curr->next;
        }
        if(x==n){
            return head->next;
        }
        x=x-n-1;
        curr=head;
        while(x--){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;

    }
};