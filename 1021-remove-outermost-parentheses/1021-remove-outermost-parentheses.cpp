class Solution {
public:
    string removeOuterParentheses(string s) {
        int cursum=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(cursum>0)
                {
                    ans=ans+s[i];
                }
                cursum++;
            }
            else
            {
                cursum--;
                if(cursum>0)
                {
                    ans+=s[i];
                }
            }     
        }
        return ans;
    }
};