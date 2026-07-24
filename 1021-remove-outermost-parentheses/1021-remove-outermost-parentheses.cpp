class Solution {
public:
    string removeOuterParentheses(string s) {
        int cursum=0;
        string ans="";
        stack<char> st;
        for(char c:s)
        {
            if(st.empty())
            {
                st.push('(');
            }     
            else if(!st.empty() && c=='(')
            {
                ans+=c;
                st.push('(');
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    ans+=c;
                }
            }
        }
        return ans;
    }
};