class Solution {
public:
    //time O(nm)
    //space O(n)
    int closedIsland(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || i==0 || j==0 || j==m-1) && a[i][j]==0) dfs(a,i,j,n,m);
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]==0) {res++;dfs(a,i,j,n,m);}
        return res;
    }
    void dfs(vector<vector<int>> &a,int i,int j,int n,int m){
        if(i < 0 || j < 0 || i >=n || j >=m || a[i][j]!=0) return;
        a[i][j]=1;
        dfs(a,i+1,j,n,m);
        dfs(a,i-1,j,n,m);
        dfs(a,i,j-1,n,m);
        dfs(a,i,j+1,n,m);
    }
};