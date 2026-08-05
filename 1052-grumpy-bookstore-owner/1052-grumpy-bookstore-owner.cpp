class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int window=0;
        int i=0;
        for(;i<minutes;i++)
        {
            if(!grumpy[i])
            {
                ans+=customers[i];
            }
            else
            {
                window+=customers[i];
            }
        }
        int maxi=window;
        for(;i<customers.size();i++)
        {
            if(!grumpy[i])
            {
                ans+=customers[i];
            }

            if(grumpy[i-minutes])
            {
                window=window-customers[i-minutes];
            }
            if(grumpy[i])
            {
                window=window+customers[i];
            }
            maxi=max(maxi,window);
        }

        return maxi+ans;
    }
};