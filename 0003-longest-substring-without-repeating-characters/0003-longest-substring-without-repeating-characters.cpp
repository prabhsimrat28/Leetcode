// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.size();
//         if(n==0||n==1)
//         {
//             return n;
//         }
//         unordered_map<char,int> occ;
//         occ[s[0]]=0;
//         int i=0,j=1;
//         int len=0;
//         while(j<n&&i<n)
//         {
//             if(occ.find(s[j])!=occ.end())
//             {
//                 while(i<occ[s[j]]+1)
//                 {
//                     occ.erase(s[i]);
//                     i++;
//                 }
//             }
//             len=max(len,j-i+1);
//             occ[s[j]]=j;
//             j++;
//         }
//         return len;
//     }
// };


 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0||n==1)
        {
            return n;
        }
        int len=0;
        
        vector<int> mp(256,-1);
        int i=0,j=1;
        mp[s[0]]=0;
        while(j<n&&i<n)
        {
            if(mp[s[j]]>=i)
            {
                i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
 };