class Solution {
public:
/*
int f(int m,int n,vector<vector<int>>&dp)
{
    if(m==0||n==0)return 1;
    if(dp[m][n]!=-1)return dp[m][n];

    int left=f(m,n-1,dp);
    int up=f(m-1,n,dp);

    dp[m][n]=left+up;
    return dp[m][n];
}*/
    int uniquePaths(int m, int n) {
        

        vector<int>dp(n,0);
        for(int j=0;j<n;j++)
        {
            dp[j]=1;
        }
        

        for(int i=1;i<m;i++){
        
            vector<int>temp(n,1);
            for(int j=1;j<n;j++)
            {
                temp[j]=dp[j]+temp[j-1];//prev+curr
            }
            dp=temp;
        }

        return dp[n-1];
        
    }
};