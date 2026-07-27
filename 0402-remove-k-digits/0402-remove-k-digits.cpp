class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        st.push(num[0]);
        for(int i=1;i<num.size();i++)
        {
            while(!st.empty() && k>0 && st.top()>num[i]) 
            {
                k--;
                st.pop();
            }
            st.push(num[i]);
        }

        while(k>0)
        {
            st.pop();
            k--;
        }

        string ans="";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        string ans2="";
        int i=0;
        while(i<ans.size() && ans[i]=='0')
        {
            i++;
        }

        while(i<ans.size())
        {
            ans2+=ans[i];
            i++;
        }

        if(ans2.size()==0)
        {
            return "0";
        }
        return ans2;
    }
};