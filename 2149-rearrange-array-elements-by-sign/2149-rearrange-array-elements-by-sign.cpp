class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posi=0;
        vector<int> ans(nums.size());
        int neg=1;
        for(int i:nums)
        {
            if(i>0)
            {
                ans[posi]=i;
                posi=posi+2;
            }
            else
            {
                //if(neg<nums.size())
                //{
                    ans[neg]=i;
                    neg=neg+2;
                //}
            }
        }
        return ans;
    }
};