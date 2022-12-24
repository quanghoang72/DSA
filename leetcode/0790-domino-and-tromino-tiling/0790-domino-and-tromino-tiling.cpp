class Solution {
public:
    long long mod=1000000007;
    int numTilings(int n) {
        if(n<3) return n;
        //fibonacci series
        long long zero=1;
        long long first=1;
        long long second=2;
        for(int i=3;i<=n;i++){
            long long temp=(second*2+zero) %mod;
            zero=first ;
            first=second ;
            second=temp;
        }
        return second%mod;
    }
};