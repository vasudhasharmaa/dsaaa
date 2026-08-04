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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(p);
        st2.push(q);
        if(p==NULL&&q==NULL)return true;
        while (!st1.empty() && !st2.empty()) {
            TreeNode* top1 = st1.top();
            TreeNode* top2 = st2.top();
          if(top1==NULL||top2==NULL)return false;
            st1.pop();
            st2.pop();
            if (top1->val != top2->val)
                return false;
            else {
                if (top1->left && top2->left) {
                    st1.push(top1->left);

                    st2.push(top2->left);
                } else if ((top1->left != NULL && top2->left == NULL)||(top2->left != NULL && top1->left == NULL))
                    return false;
                     else if ((top1->right != NULL && top2->right == NULL)||(top2->right != NULL && top1->right == NULL))
                    return false;

                if (top1->right && top2->right) {
                    st1.push(top1->right);
                    st2.push(top2->right);
                }
            }
        }
        if (st1.empty() && st2.empty())
            return true;
            return false;
    }
};