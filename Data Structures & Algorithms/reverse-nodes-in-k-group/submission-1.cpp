class Solution {
private:
    ListNode* new_head(ListNode* head, int k) {
        while(--k && head) head = head->next;
        return head;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        if(ListNode* nh = new_head(head,k)) {
            ListNode *cur = head;
            int temp = k;

            while(--k) {
                ListNode* cnext = cur->next;
                
                cur->next = cnext->next;
                cnext->next = head;
                head = cnext;
            }

            cur->next = reverseKGroup(cur->next,temp);

            return nh;
        } 
        return head;
    }
};