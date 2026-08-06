class Solution {
public:

    vector<int> x={1,-1,0,0};
    vector<int> y={0,0,1,-1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            int i =q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int i1=i+x[k];
                int j1=j+y[k];
                if(i1>=0 && i1<n && j1>=0 && j1<m && res[i1][j1]==-1)
                {
                    res[i1][j1]=1+res[i][j];
                    q.push({i1,j1});
                }
            }
        }

        return res;
    }
};