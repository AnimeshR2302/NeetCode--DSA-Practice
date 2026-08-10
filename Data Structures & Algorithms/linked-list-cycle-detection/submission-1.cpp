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
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;

        while(slow || fast) {
            if(!slow->next) return false;
            else slow = slow->next;
            
            if(!fast->next || !fast->next->next) return false;
            else fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};