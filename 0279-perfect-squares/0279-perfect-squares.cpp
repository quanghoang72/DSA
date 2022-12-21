class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n; //all 1 square
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=i; //initialize every number = 1 square *num
            for(int j=1;j*j<=i;j++){
                // +1 for the use of the j*j square
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};

// 1 2 3 4 5 6 7 8 9 10 11 12
// 1 2 3 1 2 3 4 2 1 2  3   3
