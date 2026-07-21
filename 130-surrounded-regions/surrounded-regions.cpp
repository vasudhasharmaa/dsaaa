class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board,int drow[],int dcol[])
    {
        int n=board.size();
        int m=board[0].size();

        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=r+drow[i];
            int ncol=c+dcol[i];

            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&board[nrow][ncol]=='O'&&vis[nrow][ncol]!=1)
            {
                dfs(nrow,ncol,vis,board,drow,dcol);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O'&&vis[0][j]!=1)
            {
                dfs(0,j,vis,board,drow,dcol);
                
            }

            if(board[n-1][j]=='O'&&vis[n-1][j]!=1)
            {
                dfs(n-1,j,vis,board,drow,dcol);
            }

        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O'&&vis[i][0]!=1)
            {
                dfs(i,0,vis,board,drow,dcol);
            }
            if(board[i][m-1]=='O'&&vis[i][m-1]!=1)
            {
                dfs(i,m-1,vis,board,drow,dcol);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O'&&vis[i][j]!=1)
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};