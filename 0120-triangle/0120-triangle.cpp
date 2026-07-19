class Solution {
public:


    int fun(vector<vector<int>> &tri,int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i==n-1)
        {
            return tri[n-1][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        return dp[i][j]=min(tri[i][j]+fun(tri,i+1,j,n,dp),tri[i][j]+fun(tri,i+1,j+1,n,dp));
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};