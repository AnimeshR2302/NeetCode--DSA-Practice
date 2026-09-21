class Solution {
private:
    void trav(TreeNode* cur, int &k, int& ans) {
        if(k != 0 && cur->left) trav(cur->left, k, ans);
        if(k != 0 && --k == 0) ans = cur->val;
        if(k != 0 && cur->right) trav(cur->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        trav(root, k , ans);
        return ans;
    }
};