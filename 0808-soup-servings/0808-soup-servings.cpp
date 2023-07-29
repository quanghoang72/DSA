class Solution {
public:
    // time O(n^2)
    // space O(n^2)
    double soupServings(int n) {
        if(n>4800) return 1;
        vector<pair<int,int>> dir={{-100,0},{-75,-25},{-50,-50},{-25,-75}};
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return dfs(n,n,dir,dp);
    }
    double dfs(int a,int b,vector<pair<int,int>> dir,vector<vector<double>> &dp){
        if(dp[a][b]!=-1.0)
            return dp[a][b];
        if(a<=0 && b<=0)
            return dp[a][b]=0.5;
        if(b<=0)
            return dp[a][b]=0;
        if(a<=0)
            return dp[a][b]=1;
        double res=0;
        for(auto [x,y] : dir){
            int nr=x+a <=0 ? max(0,x+a) : x+a;
            int nc=y+b <=0 ? max(0,y+b) : y+b;
            res+=0.25*(dfs(nr,nc,dir,dp));
        }
        return dp[a][b]=res;
    }
};