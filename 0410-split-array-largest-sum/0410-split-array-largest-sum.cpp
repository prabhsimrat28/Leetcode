class Solution {
public:


    bool isvalid(vector<int> &nums,int mid,int k)
    {
        long long cursum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            {
                return false;
            }
            if(cursum+nums[i]<=mid)
            {
                cursum+=nums[i];
            }
            else
            {
                k--;
                if(k==0)
                {
                    return false;
                }
                cursum=nums[i];
            }
        }
        return true;
    }


    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        int ans=-1;
        for(int i:nums)
        {
            high+=i;
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isvalid(nums,mid,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};