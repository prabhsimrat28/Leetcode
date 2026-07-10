class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        {
            if(nums.size()==1)
            return 1;
        }
        int i=0,j=1;
        int n=nums.size();
        while(j<n)
        {
            while(j<n&&nums[i]==nums[j])
            {
                j++;
            }
            if(j==n)
            break;
            i++;
            nums[i]=nums[j];
            j++;
        }
        return i+1;
    }
};