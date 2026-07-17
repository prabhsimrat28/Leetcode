class Solution {
public:

    // int fun(vector<vector<int>> &dp,string &s1,string &s2,int i,int j,int n,int m)
    // {
    //     if(i==n || j==m)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }

    //     if(s1[i]==s2[j])
    //     {
    //         return dp[i][j]=1+fun(dp,s1,s2,i+1,j+1,n,m);
    //     }
    //     return dp[i][j]=max(fun(dp,s1,s2,i+1,j,n,m),fun(dp,s1,s2,i,j+1,n,m));
    // }


    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
    //     return fun(dp,text1,text2,0,0,text1.size(),text2.size());
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};