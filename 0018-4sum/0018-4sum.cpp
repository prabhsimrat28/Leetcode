class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int d=0;d<n-3;d++)
        {
            if(d>0 && nums[d-1]==nums[d])
            {
                continue;
            }
            for(int c=d+1;c<n-2;c++)
            {
                if(c>d+1 && nums[c-1]==nums[c])
                {
                    continue;
                }
                long long req_sum=(long long)target-nums[d]-nums[c];
                int i=c+1,j=n-1;
                while(i<j)
                {
                    long long cursum=(long long)nums[i]+nums[j];
                    if(req_sum==cursum)
                    {
                        ans.push_back({nums[d],nums[c],nums[i],nums[j]});
                        i++;
                        j--;
                        while(i<j && nums[i-1]==nums[i])
                        {
                            i++;
                        }
                        while(i<j && nums[j+1]==nums[j])
                        {
                            j--;
                        }
                    }
                    else if(cursum<req_sum)
                    {
                        i++;
                    }
                    else
                    {
                        j--;
                    }
                    
                }
            }
        }
        return ans;
    }
};