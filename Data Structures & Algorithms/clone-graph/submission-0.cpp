class Solution {
private:
    Node* trav(Node* &node, unordered_map<int,Node*>& mp) {
        Node* temp = new Node(node->val);
        mp[temp->val] = temp;

        for(auto &x: node->neighbors) {
            if(mp.find(x->val) == mp.end()) Node* cnext = trav(x, mp); 
            temp->neighbors.emplace_back(mp[x->val]);
        }

        return temp;
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<int,Node*> mp;
        return trav(node, mp);
    }
};