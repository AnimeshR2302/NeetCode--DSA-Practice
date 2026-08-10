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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        while(n-- != 0) fast = fast->next;

        if(!fast) head = head->next;
        else {
            ListNode* cur = head;
            while(fast->next) {
                fast = fast->next;
                cur = cur->next;
            }

            cur->next = cur->next->next;
        }

        return head;
    }
};