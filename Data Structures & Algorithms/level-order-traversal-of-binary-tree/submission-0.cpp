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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        if(!root) return {};
        q.push({0, root});

        int prev_level = -1;
        vector<vector<int>> ans;
        vector<int> temp;
        while(!q.empty()) {
            auto [level, node] = q.front();
            q.pop();

            if(level != prev_level) {
                prev_level = level;

                if(!temp.empty()) {
                    ans.emplace_back(temp);
                    temp.clear();
                }
            }

            temp.emplace_back(node->val);
            if(node->left) q.push({level + 1, node->left});
            if(node->right) q.push({level + 1, node->right});
        }

        if(!temp.empty()) {
            ans.emplace_back(temp);
            temp.clear();
        }

        return ans;
    }
};
