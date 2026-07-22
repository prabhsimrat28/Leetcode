class Solution {
public:

    // int fun(string s1,string s2,int i,int j,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(j==m)
    //     {
    //         return 1;
    //     }
    //     if(i==n)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }

    //     if(s1[i]!=s2[j])
    //     {
    //         return dp[i][j]=fun(s1,s2,i+1,j,n,m,dp);
    //     }

    //     return dp[i][j]=fun(s1,s2,i+1,j+1,n,m,dp)+fun(s1,s2,i+1,j,n,m,dp);

    // }



    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //return fun(s,t,0,0,n,m,dp);
        for(int i=0;i<=n;i++)
        {
            dp[i][m]=1;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s[i]!=t[j])
                {
                    dp[i][j]=dp[i+1][j];
                }
                else
                {
                    dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                }
            }
        }
        return (int)dp[0][0];
    }
};