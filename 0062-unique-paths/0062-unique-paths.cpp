class Solution {
public:

    bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
            return true;

        return false;
    }


    // int fun(vector<vector<int>> &dp,int i,int j,int n,int m)
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
    //     if(isvalid(i+1,j,n,m))
    //     {
    //         down=fun(dp,i+1,j,n,m);
    //     }
    //     int right=0;
    //     if(isvalid(i,j+1,n,m))
    //     {
    //         right=fun(dp,i,j+1,n,m);
    //     }
    //     return dp[i][j]=down+right;
    // }



    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return fun(dp,0,0,m,n);
    // }

    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1]=1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(isvalid(i+1,j,m,n))
            {
                dp[i][j]+=dp[i+1][j];
            }
            if(isvalid(i,j+1,m,n))
            {
                dp[i][j]+=dp[i][j+1];
            }
        }
    }
    return dp[0][0];
    }
};