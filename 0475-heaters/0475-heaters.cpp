class Solution {
public:


    int nums_covered(vector<int> &houses,vector<int> &heaters,int rad)
    {
        int i=0,j=0;
        int n=houses.size(),m=heaters.size();
        int c=0;
        while(i<n && j<m)
        {
            int start=max(1,heaters[j]-rad);
            int finish=heaters[j]+rad;
            if(start> houses[i])
            {
                i++;
            }
            else if(houses[i]<=finish)
            {
                i++;
                c++;
            }
            else
            {
                j++;
            }
        }
        return c;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low=0,high=1e9;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int current=nums_covered(houses,heaters,mid);
            if(current<houses.size())
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};