class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
        {
            return false;
        }
        s+=s;
        int k=0;
        int len=0;
        for(int i=0;i<=s.size()-goal.size();i++)
        {
            if(s[i]==goal[0])
            {
                int j=0;
                while(j<goal.size() && s[i+j]==goal[j])
                {
                    j++;
                }
                if(j==goal.size())
                {
                    return true;
                }
            }
        }
        return false;
    }
};