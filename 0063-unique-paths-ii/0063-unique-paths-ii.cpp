class Solution {
public:

    bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }



    // int fun(vector<vector<int>> &obs,int i,int j,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(i==n-1 && j==m-1)
    //     {
    //         return 1;
    //     }

    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }

    //     int down=0;
    //     if(isvalid(i+1,j,n,m) && obs[i+1][j]!=1)
    //     {
    //         down=fun(obs,i+1,j,n,m,dp);
    //     }

    //     int right=0;
    //     if(isvalid(i,j+1,n,m) && obs[i][j+1]!=1)
    //     {
    //         right=fun(obs,i,j+1,n,m,dp);
    //     }

    //     return dp[i][j]=down+right;
    // }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int n=obstacleGrid.size();
    //     int m=obstacleGrid[0].size();
    //     if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
    //     return 0;
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return fun(obstacleGrid,0,0,n,m,dp);
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
        return 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    continue;
                }
                long long down=0;
                if(isvalid(i+1,j,n,m) && obstacleGrid[i+1][j]!=1)
                {
                    down=dp[i+1][j];
                }

                long long right=0;
                if(isvalid(i,j+1,n,m) && obstacleGrid[i][j+1]!=1)
                {
                    right=dp[i][j+1];
                }

                dp[i][j]=down+right;
            }
        }
    return dp[0][0];  
    }
};