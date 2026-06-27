class Solution {
public:

    bool valid(int &mid,int maxdays,vector<int> &nums)
    {
        int cur=1;
        int sum=0;
        for(int i:nums)
        {
            if(i+sum>mid)
            {
                cur++;
                sum=0;
            }

            sum=sum+i;
            
        }
        return maxdays>=cur;
    }



    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxi=0;
        for(int i:weights)
        {
            sum=sum+i;
            maxi=max(maxi,i);
        }
        int low=maxi,high=sum;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(mid,days,weights))
            {
                sum=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return sum;
    }
};