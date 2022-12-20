class Solution {
public:
     void dfs(vector<vector<int>>& a, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=a.size() || j<0 || j>= a[0].size() || a[i][j] == newColor || a[i][j] != val)
        {
            return;
        }
        a[i][j] = newColor;
        dfs(a,i-1,j,val,newColor);
        dfs(a,i+1,j,val,newColor);
        dfs(a,i,j-1,val,newColor);
        dfs(a,i,j+1,val,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int newColor)
    {
        int val = a[sr][sc];
        dfs(a,sr,sc,val,newColor);
        return a;
    }
};