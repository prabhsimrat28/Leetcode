class Solution {
public:

    // int fun(vector<int> &prices,int i,int n,int k,vector<vector<int>> &dp)
    // {
    //     if(i>=n)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][k]!=-1)
    //     {
    //         return dp[i][k];
    //     }

    //     if(k==1)
    //     {
    //         return dp[i][k]=max(fun(prices,i+1,n,1,dp),fun(prices,i+1,n,0,dp)-prices[i]);
    //     }
    //     return dp[i][k]=max(fun(prices,i+1,n,0,dp),prices[i]+fun(prices,i+2,n,1,dp));
    // }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //return fun(prices,0,n,1,dp);

        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k>=0;k--)
            {
                if(k==1)
                {
                    dp[i][k]=max(dp[i+1][1],dp[i+1][0]-prices[i]);
                }
                else
                {
                    if(i+2<n)
                    dp[i][k]=max(dp[i+1][0],dp[i+2][1]+prices[i]);
                    else
                    dp[i][k]=max(dp[i+1][0],prices[i]);
                }
            }
        }
        return dp[0][1];
    }
};