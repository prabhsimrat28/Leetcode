class Solution {
public:
    int minBitFlips(int start, int goal) {
      int matches=(start^goal);  
      int res=0;
      while(matches>0)
      {
        res++;
        matches=(matches & (matches-1));
      }
      return res;
    }
};