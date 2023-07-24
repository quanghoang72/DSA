class Solution {
public:
    //time O(n^2 k)
    //space O(n^2 *k)
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>> (n,vector<double>(n)));
        vector<pair<int,int>> dir={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        return dfs(dp,row,column,n,dir,k);
    }
    double dfs(vector<vector<vector<double>>> &dp,int r,int c,int n,vector<pair<int,int>> dir,int k){
        if(r <0 || r >=n || c<0 || c>=n)
            return 0;
        if(k==0)
            return dp[k][r][c]=1;
        if(dp[k][r][c]!=0)
            return dp[k][r][c];
        double temp=0;
        for(auto [x,y] : dir)
        {
            int nr=x+r;
            int nc=y+c;
            temp+=dfs(dp,nr,nc,n,dir,k-1)/8.0;
        }
        return dp[k][r][c]=temp;
    }
};
