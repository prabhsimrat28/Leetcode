class Solution {
public:

    // int fun(vector<int> &prices,int i,int n,int k,vector<vector<int>> &dp)
    // {
    //     if(i==n)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][k]!=-1)
    //     {
    //         return dp[i][k];
    //     }

    //     if(k==1)
    //     {
    //         return dp[i][k]=max(fun(prices,i+1,n,k,dp),fun(prices,i+1,n,k-1,dp)-prices[i]);
    //     }
        
    //     return dp[i][k]=max(fun(prices,i+1,n,k,dp),fun(prices,i+1,n,k+1,dp)+prices[i]);
    // }


    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>>  dp(prices.size()+1,vector<int>(2,-1));
    //     return fun(prices,0,prices.size(),1,dp);
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>  dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==1)
                {
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]-prices[i]);
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]+prices[i]);
                }
            }
        }
        return dp[0][1];
    
    }
};