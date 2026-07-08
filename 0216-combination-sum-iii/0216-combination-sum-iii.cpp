class Solution {
public:


    void fun(vector<int> &nums,vector<vector<int>> &ans,vector<int> ds,int i,int target,int &k)
    {
        if(ds.size()==k)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(i==nums.size())
        return;

        ds.push_back(nums[i]);
        fun(nums,ans,ds,i+1,target-nums[i],k);
        ds.pop_back();
        fun(nums,ans,ds,i+1,target,k);
    }




    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;
        fun(nums,ans,ds,0,n,k);
        return ans;
    }
};