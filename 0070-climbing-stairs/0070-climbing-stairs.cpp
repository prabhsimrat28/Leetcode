class Solution {
public:

    int fun(vector<int> &dp, int i,int n)
    {
        if(i==n)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int w1=fun(dp,i+1,n);
        int w2=fun(dp,i+2,n);
        return dp[i]=w1+w2;
    }


    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[n]=1;
        return fun(dp,0,n);
    }
};