class Solution {
public:

    // int fun(string &s1,int i,int j,int n,vector<vector<int>> &dp)
    // {
    //     if(i>j)
    //     {
    //         return 0;
    //     }
    //     if(i==j)
    //     {
    //         return 1;
    //     }

    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }

    //     if(s1[i]==s1[j])
    //     {
    //         return dp[i][j]=2+fun(s1,i+1,j-1,n,dp);
    //     }
    //     else
    //     {
    //         return dp[i][j]=max(fun(s1,i+1,j,n,dp),fun(s1,i,j-1,n,dp));
    //     }
    // }




    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
       // return fun(s,0,s.size()-1,s.size(),dp);
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }


        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];

    }
};