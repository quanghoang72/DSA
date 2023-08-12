class Solution {
public:
    //time O(n*m)
    //space O(n*m)
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                if(grid[i][j]!=1)
                {  
                    if(i==0){
                        dp[i][j]=dp[i][j-1];
                        continue;
                    }
                    if(j==0){
                        dp[i][j]=dp[i-1][j];
                        continue;
                    }
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
       }
        return dp[n-1][m-1];
    }
};
