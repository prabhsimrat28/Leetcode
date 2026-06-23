class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i])
            q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                int neighbor=adj[node][i];
                indegree[neighbor]--;
                if(!indegree[neighbor])
                {
                    q.push(neighbor);
                }
            }
        }

        if(ans.size()==numCourses)
        {
            return ans;
        }
        return {};


    }
};