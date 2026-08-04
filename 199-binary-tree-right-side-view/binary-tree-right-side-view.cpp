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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp; //level,node
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        if(root==NULL)return ans;

        q.push({root,0});
        while(!q.empty())
        {
            auto p=q.front();
            TreeNode* node=p.first;
            int level=p.second;
            q.pop();
            if(mp.find(level)==mp.end())
            {
                mp[level]=node->val;
            }
            if(node->right)q.push({node->right,level+1});
            if(node->left)q.push({node->left,level+1});  

        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};