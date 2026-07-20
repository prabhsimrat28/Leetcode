class Solution {
public:

    int fun(vector<int> &nums,int i,int n,int target,vector<vector<int>> &dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0 || i==n)
        {
            return 0;
        }

        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }

        return dp[i][target]=(fun(nums,i,n,target-nums[i],dp)+fun(nums,i+1,n,target,dp));
    }


    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0]=1;
        // }

        // int g = 0;
        // for (int c : coins)
        //     g = std::gcd(g, c);

        // if (amount % g != 0)
        //     return 0;

        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=1;j<=amount;j++)
        //     {
        //         dp[i][j]=dp[i+1][j];
        //         if(j>=coins[i])
        //         {
        //             dp[i][j]=dp[i][j-coins[i]]+dp[i][j];    
        //         } 
        //     }
        // }
        return fun(coins,0,n,amount,dp);
        
    }
};