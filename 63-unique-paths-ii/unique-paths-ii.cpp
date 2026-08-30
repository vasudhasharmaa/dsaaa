class Solution {
public:
/*int f(vector<vector<int>>& obstacleGrid,int r,int c,vector<vector<int>>&dp)
{
    int m=r;
    int n=c;
    if(obstacleGrid[m][n]==1) return 0;
    if(m == 0 && n == 0 && obstacleGrid[0][0] == 0)
        return 1;
    

    if(dp[m][n]!=-1)return dp[m][n];
    dp[m][n]=0;

    if(n-1>=0&&obstacleGrid[m][n-1]==0)
    {
        int left=f(obstacleGrid,m,n-1,dp);
     
        dp[m][n]+=left;
        
    }
    if(m-1>=0&&obstacleGrid[m-1][n]==0)
    {
        int up=f(obstacleGrid,m-1,n,dp);
   
        dp[m][n]+=up;
    }
    
    return dp[m][n];

}*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));

        if(obstacleGrid[0][0]==1)return 0;
        dp[0][0] = 1;
        
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[0][i]==0)dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]==0)dp[i][0]=dp[i-1][0];
        }
     

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
                else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];

    }
};