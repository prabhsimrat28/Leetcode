class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int cursum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            {
                cursum++;
            }
            if(mp.find(cursum-k)!=mp.end())
            {
                ans+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return ans;
    }
};