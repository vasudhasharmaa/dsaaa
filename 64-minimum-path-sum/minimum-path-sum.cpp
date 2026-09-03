class Solution {
public:
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
        int right=f(m-1,0,dp,grid);
        sum+=right+grid[m][n];
        return sum;
    }
    
    
    int left=f(m,n-1,dp,grid);
    int up=f(m-1,n,dp,grid);
    int choose=min(left,up);
    sum+=grid[m][n]+choose;
    return dp[m][n]=sum;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};