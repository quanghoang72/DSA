class Solution {
public:
    //time O(n^2)
    //space O(n^2)
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1]= s[i]==s[n-1-j] ? 1 + dp[i][j] : max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return n-dp[n][n];
    }
};