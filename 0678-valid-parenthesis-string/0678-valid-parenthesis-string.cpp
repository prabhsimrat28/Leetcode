class Solution {
public:

    // bool fun(string &s,int i,int balance,vector<vector<int>> &dp)
    // {
    //     if(balance<0)
    //     {
    //         return false;
    //     }
    //     if(i==s.size())
    //     {
    //         if(balance==0)
    //         {
    //             return true;
    //         }
    //         return false;
    //     }

    //     if(dp[i][balance]!=-1)
    //     {
    //         return dp[i][balance];
    //     }

    //     if(s[i]=='(')
    //     {
    //         return dp[i][balance]=fun(s,i+1,balance+1,dp);
    //     }

    //     if(s[i]==')')
    //     {
    //         return dp[i][balance]=fun(s,i+1,balance-1,dp);
    //     }

    //     return dp[i][balance]= (fun(s,i+1,balance+1,dp) || fun(s,i+1,balance-1,dp) || fun(s,i+1,balance,dp));
    // }


    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n+1,vector<bool> (n+2,false));
        //return fun(s,0,0,dp);
        
        dp[n][0]=true;

        for(int i=n-1;i>=0;i--)
        {
            for(int balance=0;balance<=n;balance++)
            {
                if(s[i]=='(')
                {
                    if(balance+1<=n)
                    dp[i][balance]=dp[i+1][balance+1];
                }
                else if(s[i]==')')
                {
                    if(balance>0)
                    dp[i][balance]=dp[i+1][balance-1];
                }
                else
                {
                    bool c1=false,c2=false,c3=false;
                    if(balance+1<=n)
                    {
                        c1=dp[i+1][balance+1];
                    }
                    if(balance>0)
                    {
                        c2=dp[i+1][balance-1];
                    }
                    c3=dp[i+1][balance];
                    dp[i][balance]=c1||c2||c3;
                }
            }
        }
        return dp[0][0];
    }
};