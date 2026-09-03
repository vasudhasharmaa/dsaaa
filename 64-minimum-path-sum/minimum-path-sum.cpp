class Solution {
public:/*
int f(int m,int n,vector<vector<int>>&dp,vector<vector<int>>&grid)
{
    int sum=0;
    if(m==0&&n==0)return grid[0][0];
    if(dp[m][n]!=-1)return dp[m][n];
    if(m==0)
    {
        int left=f(0,n-1,dp,grid);
        sum+=left+grid[m][n];
        return sum;

    }
    if(n==0)
    {
        int up=f(m-1,0,dp,grid);
        sum+=up+grid[m][n];
        return sum;
    }
    
    
    int left=f(m,n-1,dp,grid);
    int up=f(m-1,n,dp,grid);
    int choose=min(left,up);
    sum+=grid[m][n]+choose;
    return dp[m][n]=sum;
}*/
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,0);
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++)
        {
           dp[j]=dp[j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++)
        {
            vector<int>temp(n,0);
           temp[0]=dp[0]+grid[i][0];
            for(int j=1;j<n;j++)
            {
               
                int up=dp[j];
                int left=temp[j-1];
                int choose=min(up,left);
                temp[j]+=choose+grid[i][j];
            }
            dp=temp;
        }
        return dp[n-1];
    }
};