class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        //form an adj list with reverse edges as original graph
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int neighbor=graph[i][j];
                adj[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                int neighbor=adj[node][i];
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};