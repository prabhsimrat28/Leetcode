class Solution {
public:
    int minimumPushes(string word) {
        // unordered_map<char,int> mp;
        // for(char c:word)
        // {
        //     mp[c]++;
        // }

        // int sum=0;
        // priority_queue<int> pq;
        // for(auto it:mp)
        // {
        //     pq.push(it.second);
        // }

        // int multiplier=1;
        // int i=2;
        // while(!pq.empty())
        // {
        //     int freq=pq.top();
        //     pq.pop();
        //     if(i>9)
        //     {
        //         i=2;
        //         multiplier++;
        //     }
        //     sum=sum+multiplier*freq;
        //     i++;
        // }

        vector<int> freq(26,0);
        for(char c:word)
        {
            freq[c-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());

        int sum=0;
        for(int i=0;i<freq.size();i++)
        {
            sum=sum+freq[i]*((i/8)+1);
        }
        return sum;



        return sum;
    }
};