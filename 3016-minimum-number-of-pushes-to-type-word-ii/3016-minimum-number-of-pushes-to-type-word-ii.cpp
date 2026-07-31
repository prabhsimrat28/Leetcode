class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(char c:word)
        {
            mp[c]++;
        }

        int sum=0;
        priority_queue<int> pq;
        for(auto it:mp)
        {
            pq.push(it.second);
        }

        int multiplier=1;
        int i=2;
        while(!pq.empty())
        {
            int freq=pq.top();
            pq.pop();
            if(i>9)
            {
                i=2;
                multiplier++;
            }
            sum=sum+multiplier*freq;
            i++;
        }
        return sum;
    }
};