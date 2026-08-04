class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        //your code goes here
        vector<vector<int>>ans;
        int flag=0;
       
        queue<TreeNode*>q;
        if(root==NULL)return ans;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                TreeNode* topi=q.front();
                q.pop();
                if(topi->left)q.push(topi->left);
                if(topi->right)q.push(topi->right);
                level.push_back(topi->val);
                
            }
           
           if(flag==0)
           {
            ans.push_back(level);
            flag=!flag;
            
           }
           else
           {
            reverse(level.begin(),level.end());
            ans.push_back(level);
            flag=!flag;
            
           }

           
        }
        return ans;
    }
};