class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *cur, *nhead = head;
        
        while(head->next) {
            cur = head->next;
            head->next = cur->next;
            cur->next = nhead;

            nhead = cur;
        }

        return nhead;
    }
};