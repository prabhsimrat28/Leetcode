class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,cur=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cur==0)
            {
                cur++;
                ele=nums[i];
            }
            else if(nums[i]==ele)
            {
                cur++;
            }
            else
            {
                cur--;
            }
        }

        return ele;
    }
};