class Solution {
public:
void dfs(vector<int>adjLs[],vector<int>&vis,int node)
{
    vis[node]=1;
    for(auto it:adjLs[node])
    {
        if(vis[it]==0)
        {
            dfs(adjLs,vis,it);
        }
    }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adjLs[n];
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(adjLs,vis,i);
                count++; 
            }
        }
        return count;
    }
};