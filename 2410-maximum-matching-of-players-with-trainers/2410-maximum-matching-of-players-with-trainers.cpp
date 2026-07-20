class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int c=0;
        int i=0,j=0;
        while(i<players.size() && j<trainers.size())
        {
            if(trainers[j]>=players[i])
            {
                c++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return c;
    }
};