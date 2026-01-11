class Solution {
public:
    static const int MOD=1e9+7;//binary exponentiation in loop form
    long long modPow(long long base,long long exp){
        long long res = 1;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;//no. of even positions
        long long odd=n/2;//no. of odd positions
        long long ans=(modPow(5,even)*modPow(4,odd))%MOD;
        return ans;
    }
};