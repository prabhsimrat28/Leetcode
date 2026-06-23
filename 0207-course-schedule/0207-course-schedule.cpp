class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        vector<int> indegree(numCourses,0);

        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int c=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            c++;
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

        return c==numCourses;
        
    }
};