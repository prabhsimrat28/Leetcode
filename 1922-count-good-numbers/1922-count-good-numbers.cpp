class Solution {
public:

    long long MOD=1e9+7;

    int expo(int base,long long power)
    {
        if(power==0)
        {
            return 1;
        }

        long long half=expo(base,power/2) % MOD;
        if(power%2==0)
        {
            return (half*half)%MOD;
        }
        else
        {
            return (base*half*half)%MOD;
        }
    }



    int countGoodNumbers(long long n) {
        return (long long) expo(5,(n+1)/2)*expo(4,n/2) % MOD;
    }
};