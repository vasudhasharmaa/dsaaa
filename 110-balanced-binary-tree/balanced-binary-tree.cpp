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
int maxDepth(TreeNode*root)
{
    if(root==NULL)return 0;
    int maxL=maxDepth(root->left);
    int maxR=maxDepth(root->right);
    return 1+max(maxL,maxR);
}

    bool isBalanced(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)return true;
        while(!q.empty())
        {
            TreeNode* node=q.front();

            q.pop();
          
            if(abs(maxDepth(node->left)-maxDepth(node->right))<=1)
            {
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                
            }
            else
            
            {
                return false;
            }


        }
        return true;

        
    }
};