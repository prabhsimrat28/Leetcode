class Solution {
public:


    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(int i:asteroids)
        {
            if(st.empty() || st.top()<0 || i>0)
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && st.top()>0 && abs(i)>st.top())
                {
                    st.pop();
                }


                if(st.empty()||st.top()<0)//all asteriods destryed by -ve asteroid
                {
                    st.push(i);
                }
                else if(st.top()==abs(i)) //same size steroid
                {
                    st.pop();
                }
                else //some bigger +ve asteroid encountered
                {
                    continue;
                }
            }
        }

        vector<int> ans(st.size(),0);
        int i=st.size()-1;
        while(i>=0)
        {
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};