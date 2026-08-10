class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur, *prev, *nhead = new ListNode();
        cur = prev = nhead;

        do {
            cur->val += (l1? l1->val : 0) + (l2 ? l2->val : 0);
            cur->next = new ListNode(cur->val/10);
            cur->val %= 10;
            
            prev = cur;
            cur = cur->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        } while(l1 || l2);

        if(cur->val == 0) {
            prev->next = nullptr;
            delete(cur);
        }

        return nhead;
    }
};