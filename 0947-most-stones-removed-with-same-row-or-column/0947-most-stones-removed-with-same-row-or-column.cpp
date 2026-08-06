class Solution {
public:

    void fun(vector<vector<int>> &stones,int idx,vector<bool>&visited,int n)
    {
        visited[idx]=true;
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && (stones[i][0]==stones[idx][0] || stones[i][1]==stones[idx][1]))
            {
                fun(stones,i,visited,n);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,false);
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                fun(stones,i,visited,n);
                cc++;
            }
        }
        return n-cc;
    }
};