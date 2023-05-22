class Solution {
public:
    //time O(n*n)
    //space O(n*n)
    int shortestBridge(vector<vector<int>>& g) {
        int n=g.size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(g[i][j]==1){
                   dfs(g,i,j,q,n);
                   return helper(q,n,g);
               }
            }
        }
        return -1;
    }
    int helper(queue<vector<int>> &q,int n,vector<vector<int>>&g){
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int i=v[0],j=v[1],cost=v[2];

            for(int k=0;k<4;k++){
                int nX=i+dir[k];
                int nY=j+dir[k+1];

                if(nX < 0 || nX >= n || nY < 0 || nY >=n || g[nX][nY]==-1)
                    continue;
                
                if(g[nX][nY]==1) return cost;
                q.push({nX,nY,cost+1});
                g[nX][nY]=-1;
            }
        }
        return -1;
    }
    void dfs(vector<vector<int>> &g, int x,int y,queue<vector<int>> &q,int n){
        if(x < 0 || y < 0 || x >=n || y>=n || g[x][y]!=1)
            return;

        g[x][y]=2;
        int yLow= y > 0 ? y-1 : y;
        int yHigh= y < n-1 ? y+1: y;
        int xLow= x > 0 ? x-1 : x;
        int xHigh= x < n-1 ? x+1 : x;
        if(g[x][yLow]==0 || g[x][yHigh]==0 || g[xLow][y]==0 || g[xHigh][y]==0)
            q.push({x,y,0});
        dfs(g,x+1,y,q,n);
        dfs(g,x-1,y,q,n);
        dfs(g,x,y+1,q,n);
        dfs(g,x,y-1,q,n);
    }
};