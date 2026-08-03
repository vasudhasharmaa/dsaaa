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
int maxi=0;
int maxHeight(TreeNode*root)
{
    if(root==NULL)return 0;
    int maxL=maxHeight(root->left);
    int maxR=maxHeight(root->right);
    int diameter=(maxL+maxR);
    maxi=max(maxi,diameter);
    return 1+max(maxL,maxR);

}
    int diameterOfBinaryTree(TreeNode* root) {
      
        maxHeight(root);
        return maxi;

    }
};