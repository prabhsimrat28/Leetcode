class Solution {
public:

  int find_max_freq(unordered_map<char,int> &mp)
    {
        int freq=0;
        for(auto it:mp)
        {
            freq=max(freq,it.second);
        }
        return freq;
    }


    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int maxlen=-1;
        int i=0,j=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            int freq=find_max_freq(mp);
            int len=j-i+1;
            int diff=len-freq;
            while(diff>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
                len=j-i+1;
                freq=find_max_freq(mp);
                diff=len-freq;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};