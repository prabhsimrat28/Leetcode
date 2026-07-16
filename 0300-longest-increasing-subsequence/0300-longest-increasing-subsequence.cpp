class Solution {
public:

    // int fun(vector<int> &nums,int i,int n,int prev_idx,vector<vector<int>> &dp)
    // {
    //     if(i==n)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][prev_idx+1]!=-1)
    //     {
    //         return dp[i][prev_idx+1];
    //     }
    //     if(prev_idx==-1 || nums[i]>nums[prev_idx])
    //     {
    //         return dp[i][prev_idx+1]=max(1+fun(nums,i+1,n,i,dp),fun(nums,i+1,n,prev_idx,dp));
    //     }
    //     return dp[i][prev_idx+1]=fun(nums,i+1,n,prev_idx,dp);
    // }


    // int lengthOfLIS(vector<int>& nums) {
    //     vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
    //     return fun(nums,0,nums.size(),-1,dp);
    // }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    res[i]=max(res[i],1+res[j]);
                }
            }
        }

        int ans=1;
        for(int i=0;i<res.size();i++)
        {
            ans=max(ans,res[i]);
        }
        return ans;
    }
};