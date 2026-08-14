/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<int,TreeNode*>> pq;
        
        int depth= 1;
        pq.push({depth, root});

        while(!pq.empty()) {
            depth = pq.front().first;
            TreeNode* cnode = pq.front().second;
            pq.pop();
            
            if(cnode->left) pq.push({depth + 1, cnode->left});
            if(cnode->right) pq.push({depth + 1, cnode->right});
        }

        return depth;
    }
};
