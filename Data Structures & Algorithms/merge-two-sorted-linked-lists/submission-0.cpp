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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        else if(!list1) return list2;
        else if(!list2) return list1;
        else if(list1->val <= list2->val) {
            ListNode* cnext = list1->next;
            list1->next = mergeTwoLists(cnext, list2);
            return list1;
        } else {
            ListNode* cnext = list2->next;
            list2->next = mergeTwoLists(list1, cnext);
            return list2;
        }
    }
};