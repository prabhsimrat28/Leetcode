class Solution {
public:


    // int fun(vector<int> &prices,int i,int n,int k,vector<vector<int>> &dp)
    // {
    //     if(i==n ||k==0)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][k]!=-1)
    //     {
    //         return dp[i][k];
    //     }

    //     if(k%2==0)
    //     {
    //         return dp[i][k]= max(fun(prices,i+1,n,k,dp),fun(prices,i+1,n,k-1,dp)-prices[i]);
    //     }
    //     else
    //     {
    //         return dp[i][k]= max(fun(prices,i+1,n,k,dp),fun(prices,i+1,n,k-1,dp)+prices[i]);
    //     }
    // }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (5,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k<=4;k++)
            {
                if(k%2==0)
                {
                    dp[i][k]=max(dp[i+1][k],dp[i+1][k-1]-prices[i]);
                }
                else
                {
                    dp[i][k]=max(dp[i+1][k],dp[i+1][k-1]+prices[i]);
                }
            }
        }
        return max(0,dp[0][4]);
    }
};