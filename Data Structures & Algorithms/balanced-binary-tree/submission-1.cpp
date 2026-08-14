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
private:
    pair<int, bool> checkfun(TreeNode* node) {
        if(!node) return {0, true};

        auto [ldepth, lbal] = checkfun(node->left);
        auto [rdepth, rbal] = checkfun(node->right);

        auto cur_depth = max(ldepth, rdepth) + 1;
        auto is_bal = (abs(ldepth - rdepth) < 2) && lbal && rbal;

        return {cur_depth, is_bal};
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkfun(root).second;
    }
};
