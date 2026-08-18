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
    void dfs(TreeNode* node, int& depth, vector<int>& ans) {
        if(!node) return;
        if(ans.size() == depth) ans.emplace_back(node->val);
        
        depth++;
        dfs(node->right, depth, ans);
        dfs(node->left, depth, ans);
        depth--;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int depth = 0;

        dfs(root, depth, ans);

        return ans;
    }
};
