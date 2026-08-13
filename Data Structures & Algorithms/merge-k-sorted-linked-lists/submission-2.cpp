class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype([](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        })> pq;

        ListNode* nhead = new ListNode();
        ListNode* todel, *cur;
        todel = cur = nhead;
        
        vector<ListNode*> curs;
        
        for(auto &x: lists) if(x) pq.push(x);

        while(!pq.empty()) {
            cur->next = pq.top();
            pq.pop();

            cur = cur->next;
            if(cur->next) pq.push(cur->next);
        }

        nhead = nhead->next;
        delete(todel);
                
        return nhead;
    }
};