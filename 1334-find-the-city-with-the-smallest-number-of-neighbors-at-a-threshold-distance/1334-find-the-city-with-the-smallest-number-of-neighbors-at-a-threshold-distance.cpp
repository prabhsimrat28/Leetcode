class Solution {
public:

    int dij(vector<vector<pair<int,int>>> &adj,int src,int &maxdis,int &n)
    {
        int reachable=0;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        minheap.push({0,src});
        while(!minheap.empty())
        {
            int node=minheap.top().second;
            int d_till_node=minheap.top().first;
            minheap.pop();
            if(d_till_node>dist[node])
            {
                continue;
            }
            for(int j=0;j<adj[node].size();j++)
            {
                int neighbor=adj[node][j].first;
                int w=adj[node][j].second;
                if(w+d_till_node<dist[neighbor])
                {
                    dist[neighbor]=w+d_till_node;
                    minheap.push({w+d_till_node,neighbor});
                }
            }
        }



        for(int i:dist)
        {
            if(i<=maxdis)
            reachable++;
        }
        return reachable;
    }




    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mini=INT_MAX;
        int res=-1;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        for(int i=0;i<n;i++)
        {
            int val=dij(adj,i,distanceThreshold,n);
            if(val<=mini)
            {
                mini=val;
                res=i;
            }
        }
        cout<<mini;

        return res;
    }
};