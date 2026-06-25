class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int nrow=grid.size();
        int ncol=grid[0].size();
        vector<vector<int>> dist(nrow,vector<int> (ncol,INT_MAX));
        dist[0][0]=grid[0][0];;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(d>dist[row][col])
            {
                continue;
            }

            for(int k=0;k<4;k++)
            {
                int r1=row+x[k];
                int c1=col+y[k];
                if(r1<0 || r1>=nrow || c1<0 || c1>=ncol)
                {
                    continue;
                }
                int newmoney=max(d,grid[r1][c1]);
                if(newmoney<dist[r1][c1])
                {
                    dist[r1][c1]=newmoney;
                    pq.push({dist[r1][c1],{r1,c1}});
                }
            }
        }
        return dist[nrow-1][ncol-1];
    }
};