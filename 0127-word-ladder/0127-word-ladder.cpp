class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_map<string,int> m;
       for(string i:wordList)
       {
            m[i]++;
       }

       if(m.find(endWord)==m.end())
       {
        return 0;
       }

       if(m.find(beginWord)==m.end())
       {
        m[beginWord]=1;
       }

       queue<pair<string,int>> q;
       q.push({beginWord,1});
       m.erase(beginWord);
       while(!q.empty())
       {
            string s=q.front().first;
            int val=q.front().second;
            q.pop();
            if(s==endWord)
            {
                return val;
            }

            for(int i=0;i<s.size();i++)
            {
                char c=s[i];
                for(int j=97;j<123;j++)
                {
                    if(c==j)
                    {
                        continue;
                    }
                    s[i]=j;
                    if(m.find(s)!=m.end())
                    {
                        q.push({s,val+1});
                        m.erase(s);
                    }
                }
                s[i]=c;
            }
       }
       return 0;
    }
};