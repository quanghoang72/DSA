class Solution {
public:
    //time O(sizeof(a)*k)
    //time O(n*k)
    int maxValueOfCoins(vector<vector<int>>& a, int k) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return dfs(0,k,a,n,dp);
    }
    int dfs(int i,int coin,vector<vector<int>>&a,const int &n,vector<vector<int>>&dp){
        if(i==n) 
            return 0;
        
        if(dp[i][coin]!=-1) //cache
            return dp[i][coin];
        
        dp[i][coin]=dfs(i+1,coin,a,n,dp); //skip the current pile
        int curValue=0;
        
        for(int j=0;j<min((int)a[i].size(),coin);j++){
            curValue+=a[i][j];
            dp[i][coin]=max(dp[i][coin],curValue+dfs(i+1,coin-1-j,a,n,dp));
        }
        return dp[i][coin];
    }
};