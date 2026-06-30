class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int nrow=grid.size(),ncol=grid[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        //input all boundary 1s in queue
        //then from each one start bfs and mark the inner 1s that can be visited as 0.
        //vount no of ones in the end
        for(int i=0;i<nrow;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                grid[i][0]=0;
            }
        }
        for(int i=0;i<nrow;i++)
        {
            if(grid[i][ncol-1]==1)
            {
                q.push({i,ncol-1});
                grid[i][ncol-1]=0;
            }
        }

        for(int i=0;i<ncol;i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                grid[0][i]=0;
            }
        }
        for(int i=0;i<ncol;i++)
        {
            if(grid[nrow-1][i]==1)
            {
                q.push({nrow-1,i});
                grid[nrow-1][i]=0;
            }
        }

        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int row=i+x[k];
                int col=j+y[k];
                if(row>=0 && row<nrow && col>=0 && col<ncol && grid[row][col]==1)
                {
                    grid[row][col]=0;
                    q.push({row,col});
                }
            }
        }

        for(int i=0;i<nrow;i++)
        {
            for(int j=0;j<ncol;j++)
            {
                if(grid[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};