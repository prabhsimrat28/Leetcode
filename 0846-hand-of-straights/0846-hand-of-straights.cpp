class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        

        if(hand.size()%groupSize!=0)
        {
            return false;
        }

        sort(hand.begin(),hand.end());

        map<int,int> mp;
        
        for(int i:hand)
        {
            mp[i]++;
        }

        while(!mp.empty())
        {
            int start=mp.begin()->first;
            for(int i=start;i<start+groupSize;i++)
            {
                if(mp.find(i)==mp.end())
                {
                    return false;
                }
                mp[i]--;
                if(mp[i]==0)
                {
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};