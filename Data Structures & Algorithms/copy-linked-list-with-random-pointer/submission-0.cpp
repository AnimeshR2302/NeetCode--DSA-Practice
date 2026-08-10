/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        int oidx, idx;
        oidx = idx = 0;
        
        unordered_map<Node*, int> orig;
        unordered_map<int, Node*> mp;

        Node* nhead = new Node(head->val);
        Node *prev = nhead, *onext = head->next;
        
        orig[head] = oidx++;
        mp[idx++] = prev;

        while(onext){
            prev->next = new Node(onext->val);
            prev = prev->next;

            mp[idx++] = prev;
            orig[onext] = oidx++;

            onext = onext->next;
        }

        onext = head;
        prev = nhead;

        while(onext) {
            if(orig.find(onext->random) == orig.end()) prev->random = nullptr;
            else prev->random = mp[orig[onext->random]];
        
            onext = onext->next;
            prev = prev->next;
        }

        return nhead;
    }
};