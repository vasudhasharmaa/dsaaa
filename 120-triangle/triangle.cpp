class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&triangle)
{
    int m=triangle.size();
    int sum=0;
    if(dp[i][j]!=INT_MAX)
    {
        return dp[i][j];
    }
    if(i==m-1)
    {
        return dp[i][j]=triangle[i][j];
    }
   

    
    int down=triangle[i][j]+f(i+1,j,dp,triangle);
    int dia=triangle[i][j]+f(i+1,j+1,dp,triangle);
    int choose=min(down,dia);
    sum+=choose;
    return dp[i][j]=sum;

}
    int minimumTotal(vector<vector<int>>& triangle) {
       int m=triangle.size();
       vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
    return f(0,0,dp,triangle);
    }
};