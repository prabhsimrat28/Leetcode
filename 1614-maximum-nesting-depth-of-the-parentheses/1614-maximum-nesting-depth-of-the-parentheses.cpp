class Solution {
public:
    int maxDepth(string s) {
        int cursum=0;
        int maxi=0;
        int i=0;
        while(i<s.size())
        {
            if(s[i]==')')
            {
                cursum--;
            }
            else if(s[i]=='(')
            {
                cursum++;
                maxi=max(cursum,maxi);
            }
            i++;
        }

        return maxi;
    }
};