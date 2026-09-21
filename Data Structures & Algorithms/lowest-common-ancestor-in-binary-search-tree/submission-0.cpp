class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val) || (p->val == root->val || q->val == root->val))
                break;
            else if(p->val < root->val && q->val < root->val) root = root->left;
            else root =root->right;
        }

        return root;
    }
};