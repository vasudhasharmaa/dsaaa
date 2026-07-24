class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>&graph,int color[])
    {
        color[node]=col;//0 assigned in array
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!col,graph,color)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        
        int color[V];
        for(int i=0;i<V;i++)color[i]=-1;

        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,graph,color)==false)return false;
            }
        }
        return true;
    }
};