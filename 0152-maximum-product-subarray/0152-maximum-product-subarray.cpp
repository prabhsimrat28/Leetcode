class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int curmax=1,curmin=1;
        for(int i:nums)
        {
            if(i==0)
            {
                curmin=1,curmax=1;
                continue;
            }
            int t=curmax*i;
            curmax=max(i,max(i*curmax,i*curmin));
            curmin=min(i,min(i*curmin,t));
            ans=max(ans,curmax);
        }
        return ans;
    }
};