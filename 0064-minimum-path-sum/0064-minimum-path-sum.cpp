class Solution {
public:

    bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }

    // int fun(vector<vector<int>> &grid,int i,int j,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(i==n-1 && j==m-1)
    //     {
    //         return grid[i][j];
    //     }

    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }

    //     int down=INT_MAX;
    //     if(isvalid(i+1,j,n,m))
    //     {
    //         down=grid[i][j]+fun(grid,i+1,j,n,m,dp);
    //     }

    //     int right=INT_MAX;
    //     if(isvalid(i,j+1,n,m))
    //     {
    //         right=grid[i][j]+fun(grid,i,j+1,n,m,dp);
    //     }

    //     return min(down,right);
    // }


    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    continue;
                }
                int down=INT_MAX;
                if(isvalid(i+1,j,n,m))
                {
                    down=grid[i][j]+dp[i+1][j];
                }

                int right=INT_MAX;
                if(isvalid(i,j+1,n,m))
                {
                    right=grid[i][j]+dp[i][j+1];
                }

                dp[i][j]=min(down,right);
            }
        }
        return dp[0][0];
    }
};