/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int maxL = maxDepth(root->left);
        int maxR = maxDepth(root->right);

        return 1 + max(maxL, maxR);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            int right = maxDepth(node->right);
            int left = maxDepth(node->left);
            if ((abs(right - left) > 1))
                return false;

            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
            
        }
        if(st.empty())return true;
        return false;
    }
};