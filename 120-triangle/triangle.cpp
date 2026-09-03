class Solution {
public:
    /*int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&triangle)
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

    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>dp(m,INT_MAX);
        int sum=0;
        for(int j=0;j<m;j++)
        {
            dp[j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--)
        {
            vector<int>temp(m);
            for(int j=0;j<=i;j++)
            {
                int choose=min(dp[j],dp[j+1]);
                temp[j]=choose+triangle[i][j];


            }
            dp=temp;
        }
        return dp[0];
    }
};