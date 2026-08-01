class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
        {
            return {newInterval};
        }
        vector<vector<int>> ans;
        int i=0;
        int n=intervals.size();

        while(i<n && newInterval[0]> intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        if(i==n)
        {
            ans.push_back(newInterval);
            return ans;
        }

        //no overlap
        if(newInterval[1]< intervals[i][0])
        {
            ans.push_back(newInterval);
        }

        //overlap
        else
        {
            int newstart=min(newInterval[0],intervals[i][0]);
            int newfinish=max(newInterval[1],intervals[i][1]);
            ans.push_back({newstart,newfinish});
            i++;
            while(i<n && ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                i++;
            }

        }

        //remaining
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};