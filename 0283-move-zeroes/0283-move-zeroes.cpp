class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        for(int right=0;right<n;right++)
        {
            if(nums[right]!=0)
            {
                nums[left]=nums[right];
                left++;
            }
        }
        while(left<n)
        {
            nums[left]=0;
            left++;
        }
    }
};