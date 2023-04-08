class Solution {
public:
    int numEnclaves(vector<vector<int>>& a) {
        int res=0;
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && (i*j==0 || i==n-1 || j==m-1))
                    dfs(a,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]) res++;
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &a,int i,int j,int n,int m){
        if(i < 0 || j < 0 || i ==n || j==m || a[i][j]==0) return;
        a[i][j]=0;
        dfs(a,i+1,j,n,m);
        dfs(a,i-1,j,n,m);
        dfs(a,i,j+1,n,m);
        dfs(a,i,j-1,n,m);
    }
};