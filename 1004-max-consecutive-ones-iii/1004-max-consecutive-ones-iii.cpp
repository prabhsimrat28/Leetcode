class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<n&&i<n)
        {
            if(nums[j]==0)
            {
                //use 1 k
                if(k>0)
                {
                    k--;
                }

                else
                {
                    while(k==0)
                    {
                        if(nums[i]==0)
                        {
                            k++;
                        }
                        i++;
                    }
                    k--;
                }
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};