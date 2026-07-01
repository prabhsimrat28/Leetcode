class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return -1;
        }

        if(n==1)
        return 1;
        
        vector<int> x={1,0,1,-1,0,-1,1,-1};
        vector<int> y={1,1,0,0,-1,-1,-1,1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0]=1;
        while(!q.empty())
        {
            int i=q.front().second.first;
            int j=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int k=0;k<8;k++)
            {
                int i1=i+x[k];
                int j1=j+y[k];
                if(i1==n-1 && j1==n-1)
                {
                   return d+1;
                }
                if(i1>=0 && i1<n && j1>=0 && j1<n && grid[i1][j1] == 0)
                {
                    q.push({d+1,{i1,j1}});
                    grid[i1][j1]=1;
                }
            }
        }
        return -1;
    }
};