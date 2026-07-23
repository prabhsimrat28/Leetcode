class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c:s)
        {
            mp[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }

        string ans="";
        while(!pq.empty())
        {
            int val=pq.top().second;
            string a(pq.top().first,val);
            pq.pop();
            ans.append(a);
        }
        return ans;
    }
};