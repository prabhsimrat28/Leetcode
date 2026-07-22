class Solution {
public:


    // int fun(vector<int> &prices,int i,int n,int k,int fee,vector<vector<int>> &dp)
    // {
    //     if(i>=n)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][k]!=-1)
    //     {
    //         return dp[i][k];
    //     }

    //     if(k==1)//i have option to skip or buy by paying transaction fee
    //     {
    //         return dp[i][k]=max(fun(prices,i+1,n,k,fee,dp),fun(prices,i+1,n,k-1,fee,dp)-prices[i]-fee);
    //     }

    //     return dp[i][k]=max(fun(prices,i+1,n,k,fee,dp),fun(prices,i+1,n,k+1,fee,dp)+prices[i]);
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //return fun(prices,0,n,1,fee,dp);

        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k>=0;k--)
            {
                if(k==1)
                {
                    dp[i][k]=max(dp[i+1][k],dp[i+1][k-1]-prices[i]-fee);
                }
                else
                {
                    dp[i][k]=max(dp[i+1][k],dp[i+1][k+1]+prices[i]);
                }
            }
        }

        return dp[0][1];
    }
};