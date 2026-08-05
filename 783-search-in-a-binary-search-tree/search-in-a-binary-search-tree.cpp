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
    TreeNode* searchBST(TreeNode* root, int val) {
        stack<TreeNode*>st;
        if(root==NULL )return NULL;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            if(node->val!=val)
            {
                if(node->val<val)
                {
                    if(node->right!=NULL)
                    st.push(node->right);
                }
                else 
                {
                    if(node->left!=NULL)st.push(node->left);
                }
            }
            else
            {
                return node;
            }
        }
        return NULL;
    }
};