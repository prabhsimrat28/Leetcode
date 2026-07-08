class Solution {
public:

    void fun(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,int i,int n)
    {
        if(i==n)
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        fun(nums,ans,ds,i+1,n);
        ds.pop_back();
        int idx=i+1;
        while(idx<n&&nums[idx]==nums[i])
        {
            idx++;
        }
        fun(nums,ans,ds,idx,n);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        fun(nums,ans,ds,0,nums.size());
        return ans;
    }
};