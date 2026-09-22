class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        int rootval = preorder.front();
        TreeNode* root = new TreeNode(rootval);

        if (preorder.size() == 1)
            return root;

        int splitIdx = distance(
            inorder.begin(),
            find(inorder.begin(), inorder.end(), rootval)
        );

        vector<int> leftPre(
            preorder.begin() + 1,
            preorder.begin() + splitIdx + 1
        );

        vector<int> rightPre(
            preorder.begin() + splitIdx + 1,
            preorder.end()
        );

        vector<int> leftIn(
            inorder.begin(),
            inorder.begin() + splitIdx
        );

        vector<int> rightIn(
            inorder.begin() + splitIdx + 1,
            inorder.end()
        );

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};