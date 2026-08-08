class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum=0;
        int min_sum=0;
        int cur_sum=0;
        int n=cardPoints.size();
        for(int i=0;i<n;i++)
        {
            total_sum+=cardPoints[i];
            if(i<n-k)
            {
                cur_sum+=cardPoints[i];
                min_sum=cur_sum;
            }
            else
            {
                cur_sum=cur_sum+cardPoints[i]-cardPoints[i-n+k];
                min_sum=min(min_sum,cur_sum);
            }
            
        }
        return (int)(total_sum-min_sum);

    }
};