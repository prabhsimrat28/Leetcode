class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        vector<int> dist(n,INT_MAX);
        minheap.push({0,k-1});
        dist[k-1]=0;
        while(!minheap.empty())
        {
            int node=minheap.top().second;
            int d=minheap.top().first;
            minheap.pop();
            if(d>dist[node])
            {
                continue;
            }

            for(int i=0;i<adj[node].size();i++)
            {
                int neighbor=adj[node][i].first;
                int w=adj[node][i].second;
                if(d+w<dist[neighbor])
                {
                    dist[neighbor]=d+w;
                    minheap.push({d+w,neighbor});
                }
            }
        }

        int maxi=*max_element(dist.begin(),dist.end());
        if(maxi==INT_MAX)
        {
            return -1;
        }
        return maxi;
    }
};