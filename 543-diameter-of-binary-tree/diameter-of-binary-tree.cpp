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
int maxDepth(TreeNode*root)
{
    if(root==NULL)return 0;
    int maxL=maxDepth(root->left);
    int maxR=maxDepth(root->right);
    int dia=maxL+maxR;
    maxi=max(dia,maxi);

    return 1+max(maxL,maxR);
}
    int diameterOfBinaryTree(TreeNode* root) {
       maxDepth(root);
        return maxi;
    }
};