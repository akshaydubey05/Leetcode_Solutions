class Solution {
public:
    // Comparator struct to make priority_queue a Min-Heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the head of each non-empty list into the heap
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract min, attach to result, push next node from that list
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            
            tail->next = top;
            tail = tail->next;
            
            if (top->next) {
                pq.push(top->next);
            }
        }
        return dummy.next;
    }
};