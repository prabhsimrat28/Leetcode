class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }

        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        int connected_components=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int j=0;j<adj[node].size();j++)
                {
                    if(!visited[adj[node][j]])
                    {
                        visited[adj[node][j]]=true;
                        q.push(adj[node][j]);
                    }
                }
            }
            connected_components++;
        }
        return connected_components-1;
    }
};