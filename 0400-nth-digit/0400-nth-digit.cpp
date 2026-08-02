class Solution {
public:

    long long countdigits(long long n)
    {
        long long len=1;
        long long start=1;
        long long digits=0;
        while(start*10<=n)
        {
            digits=digits+(start*10-start)*len;
            len++;
            start=start*10;
        }
        digits += (n - start + 1) * len;
        return digits;
    }


    int findNthDigit(int n) {
        long long low=1,high=n;


        long long digits=0;
        int idx=-1;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            digits=countdigits(mid);
            if(digits==n)
            {
                idx=mid;
                break;
            }
            else if(digits<n)
            {
                low=mid+1;
            }
            else
            {
                idx=mid;
                high=mid-1;
            }
        }
        digits=countdigits(idx);
        int displace=digits-n;
        while(displace>0)
        {
            idx=idx/10;
            displace--;
        }
        return idx%10;
    }
};