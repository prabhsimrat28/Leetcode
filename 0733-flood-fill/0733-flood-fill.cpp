class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og=image[sr][sc];
        int nrow=image.size(),ncol=image[0].size();
        queue<pair<int,int>> q;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        q.push({sr,sc});
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(image[i][j]==color)
            {
                continue;
            }
            image[i][j]=color;
            
            for(int k=0;k<4;k++)
            {
                int row=i+x[k];
                int col=j+y[k];
                if(row>=0 && row<nrow && col>=0 && col<ncol && image[row][col]==og)
                {
                    q.push({row,col});
                }
            }
        }
        return image;
    }
};