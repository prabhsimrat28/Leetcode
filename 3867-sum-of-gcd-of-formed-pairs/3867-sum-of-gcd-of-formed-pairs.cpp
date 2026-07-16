class Solution {
public:

    int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    long long gcdSum(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        vector<int> prefixgcd;
        prefixgcd.push_back(nums[0]);
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxi=max(nums[i],maxi);
            prefixgcd.push_back(gcd(maxi,nums[i]));
        }

        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=prefixgcd.size()-1;
        long long sum=0;
        while(i<j)
        {
            sum=sum+gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};