class Solution {
public:
    string removeOuterParentheses(string s) {
        int cursum=0;
        string ans="";
        for(char c:s)
        {
            if(c=='(')
            {
                if(cursum>0)
                {
                    ans=ans+c;
                }
                cursum++;
            }
            else
            {
                cursum--;
                if(cursum>0)
                {
                    ans+=c;
                }
            }     
        }
        return ans;
    }
};