class Solution {
public:

    void make0(int i,int j,vector<vector<int>>& matrix,int n,int m)
    {
        for(int k=0;k<m;k++)
        {
            matrix[i][k]=0;
        }
        for(int k=0;k<n;k++)
        {
            matrix[k][j]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> st;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    st.insert({i,j});
                }
            }
        }

        while(!st.empty())
        {
            auto p=*st.begin();
            int row=p.first;
            int col=p.second;
            make0(row,col,matrix,n,m);
            st.erase({row,col});
        }
    }
};