class Solution {
public:
    //time O(n)
    //space O(n)
    long long mostPoints(vector<vector<int>>& a) {
        int n=a.size();
        vector<long long> dp(n+1);
        for(int i=n-1;i>=0;i--){
            int points=a[i][0];
            int skip=a[i][1];
            dp[i]=max(dp[i+1], dp[min(n,skip+i+1)]  + points );
        }
        return dp[0];
    }
};