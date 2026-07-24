class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&grid,int drow[],int dcol[] )
{
    vis[r][c]=1;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++)
    {
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]=='1'&&vis[nrow][ncol]==0)
        {
            dfs(nrow,ncol,vis,grid,drow,dcol);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]=='1'&&vis[0][j]!=1)
            {
                dfs(0,j,vis,grid,drow,dcol);
                count++;
            }
            if(grid[n-1][j]=='1'&&vis[n-1][j]!=1)
            {
                dfs(n-1,j,vis,grid,drow,dcol);
                count++;
            }

        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]=='1'&&vis[i][0]=='1')
            {
                dfs(i,0,vis,grid,drow,dcol);
                count++;
            }
            if(grid[i][m-1]=='1'&&vis[i][m-1]!=1)
            {
                dfs(i,m-1,vis,grid,drow,dcol);
                count++;
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]!=1)
                {
                    dfs(i,j,vis,grid,drow,dcol);
                    count++;
                }
            }
        }
        return count;

    }
};