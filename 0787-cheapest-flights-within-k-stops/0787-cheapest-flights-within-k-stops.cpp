class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<k+1;i++)
        {
            vector<int> prev=dist;
            for(int j=0;j<flights.size();j++)
            {
                int s=flights[j][0];
                int des=flights[j][1];
                int d=flights[j][2];
                if(dist[s]==INT_MAX)
                {
                    continue;
                }
                if(d+dist[s]<prev[des])
                {
                    prev[des]=d+dist[s];
                }
            }
            dist=prev;
        }
        if(dist[dst]==INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};