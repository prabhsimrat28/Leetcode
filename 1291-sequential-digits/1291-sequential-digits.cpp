class Solution {
public:

    void give_seq_num(int start,int &low,int &high,int val,vector<int> &ans)
    {
        if(val>high)
        return;

        if(val>=low)
        {
            ans.push_back(val);
        }

        if(start>9)
        return;
        
        give_seq_num(start+1,low,high,val*10+start,ans);

    }


    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            give_seq_num(i+1,low,high,i,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};