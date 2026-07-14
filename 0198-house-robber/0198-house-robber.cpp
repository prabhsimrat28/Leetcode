class Solution {
public:

//     int fun(int n,vector<int> &dp,vector<int> &nums)
//     {
//         if(n==0)
//         return nums[0];
//         if(n==1)
//         return max(nums[0],nums[1]);
//         if(dp[n]!=-1)
//         return dp[n];

//         return dp[n]=max(nums[n]+fun(n-2,dp,nums),fun(n-1,dp,nums));
//     }


//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return fun(nums.size()-1,dp,nums);
//     }


        int fun(vector<int> &nums,int i,int n,vector<int> &dp)
        {
            if(i>=n)
            {
                return 0;
            }

            //take
            if(dp[i]!=-1)
            {
                return dp[i];
            }
            int take=nums[i]+fun(nums,i+2,n,dp);
            int nottake=fun(nums,i+1,n,dp);
            return dp[i]=max(take,nottake);
        }


        int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        //dp[0]=nums[0];
        return fun(nums,0,nums.size(),dp);
    }
};
//  class Solution {
//  public:

//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)
//         return nums[0];
//         if(n==2)
//         return max(nums[0],nums[1]);
//         vector<int>dp(n,-1);
//         dp[0]=nums[0];
//         dp[1]=max(nums[0],nums[1]);
//         for(int i=2;i<n;i++)
//         {
//             dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
//         }
//         return dp[n-1];

//     }
// };