class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		sum=max(sum+nums[i],nums[i]);
		maxi=max(maxi,sum);
	}
	return maxi;
    }
};