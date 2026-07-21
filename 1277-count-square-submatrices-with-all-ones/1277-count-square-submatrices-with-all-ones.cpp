class Solution {
public:

    int fun(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        if(i==n || j==m)
        {
            return 0;
        }
        if(matrix[i][j]==0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int down=fun(i+1,j,n,m,matrix,dp);
        int right=fun(i,j+1,n,m,matrix,dp);
        int diagonal=fun(i+1,j+1,n,m,matrix,dp);
        return dp[i][j]=1+min(down,min(right,diagonal));
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int c=0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(matrix[i][j]==1)
        //         {
        //             c=c+fun(i,j,n,m,matrix,dp);
        //         }
        //     }
        // }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(matrix[i][j]==1)
                {
                    int down=dp[i+1][j];
                    int right=dp[i][j+1];
                    int diagonal=dp[i+1][j+1];
                    dp[i][j]=1+min(down,min(right,diagonal));
                    c+=dp[i][j];
                }
            }
        }
        return c;
    }
};