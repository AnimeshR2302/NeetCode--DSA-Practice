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
private:
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

public:
    void reorderList(ListNode* head) {
        ListNode *slow, *fast, *cs, *cf;
        slow=fast=head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        slow = head;
        fast = reverseList(fast);
        
        cs = slow;
        cf = fast;

        while(cf) {
            slow = slow->next; 
            fast = fast->next;

            cs->next = cf;
            cf->next = slow;

            cs = slow;
            cf = fast;
        }
    }
};