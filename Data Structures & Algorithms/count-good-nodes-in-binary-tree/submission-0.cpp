class Solution {
private:
    void trav(TreeNode* node, int cmax, int& ans) {
        if(!node) return;
        if(node->val >= cmax) {
            cmax = node->val;
            ans++;
        }

        trav(node->left,cmax,ans);
        trav(node->right,cmax,ans);
    }

public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        trav(root, INT_MIN, ans);
        return ans;
    }
};
