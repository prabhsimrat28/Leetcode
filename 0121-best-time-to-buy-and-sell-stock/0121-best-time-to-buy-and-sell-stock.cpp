class Solution {
public:

    // int fun(vector<vector<int>> &dp,vector<int> &prices,int i,int n,int k)
    // {
    //     if(i==n || k==0)
    //     {
    //         return 0;
    //     }

            // if(dp[i][k]!=-1)
            // {
            //     return dp[i][k];
            // }

    //     if(k==2)
    //     {
    //         return dp[i][k]=max(fun(dp,prices,i+1,n,k),fun(dp,prices,i+1,n,k-1)-prices[i]);
    //     }

    //     else
    //     {
    //         return dp[i][k]=max(fun(dp,prices,i+1,n,k),prices[i]+fun(dp,prices,i+1,n,k-1));
    //     }
    // }


    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>> dp(prices.size()+1,vector<int>(3,-1));
    //     return max(0,fun(dp,prices,0,prices.size(),2));
    // }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int k=1;k<=2;k++)
            {
                if(k==1)
                {
                    dp[i][k]=max(dp[i+1][k],prices[i]+dp[i+1][k-1]);
                }
                else
                {
                    dp[i][k]=max(dp[i+1][k],dp[i+1][k-1]-prices[i]);
                }   
            }
        }
        return max(0,dp[0][2]);
    }
};