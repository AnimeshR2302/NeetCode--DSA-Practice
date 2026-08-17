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
    int childlen(TreeNode* node, int &maxx) {
        if(!node) return 0;

        int leftlen = childlen(node->left, maxx);
        int rightlen = childlen(node->right, maxx);

        maxx = max(leftlen + rightlen, maxx);
        return max(leftlen, rightlen) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx = 0;
        childlen(root, maxx);

        return maxx;
    }
};
