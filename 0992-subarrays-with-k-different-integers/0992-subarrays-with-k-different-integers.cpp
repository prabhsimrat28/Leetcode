class Solution {
public:

    int find_number_of_subarrays_with_atmost_k_distinct(vector<int>&nums,int k)
    {
        int c=0;
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            c=c+(j-i+1);
            j++;
        }
        return c;

    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {  
        return find_number_of_subarrays_with_atmost_k_distinct(nums,k)-find_number_of_subarrays_with_atmost_k_distinct(nums,k-1);
    }
};