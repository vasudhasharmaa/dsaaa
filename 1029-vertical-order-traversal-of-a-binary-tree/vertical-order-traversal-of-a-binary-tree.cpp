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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;//vertices,levels+multiples nodes
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int vertix=p.second.first;
            int level=p.second.second;
            nodes[vertix][level].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{vertix-1,level+1}});
            }
            if(node->right)
            {
                q.push({node->right,{vertix+1,level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it1:nodes)
        {
            vector<int>colwise;
            for(auto it2:it1.second )
            {
                colwise.insert(colwise.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(colwise);
        }
        return ans;
    }

};