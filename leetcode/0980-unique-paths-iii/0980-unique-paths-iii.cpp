class Solution {
public:
    
    int res=0,empty=1;
    //empty to count all empty cells
    void dfs(vector<vector<int>> &a,int x,int y,int count){
        if(x<0 || x>=a.size() || y<0 || y>=a[0].size() || a[x][y]==-1) return;
        
        if(a[x][y]==2){ //reach end point
            if(count==empty) res++; //if we have traverse all the empty cells
            return;
        } 
        a[x][y]=-1; //vistied
        dfs(a,x+1,y,count+1);
        dfs(a,x-1,y,count+1);
        dfs(a,x,y+1,count+1);
        dfs(a,x,y-1,count+1);
        a[x][y]=0;//reset
    }
    int uniquePathsIII(vector<vector<int>>& a) {
        int startx,starty;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]==1){
                    startx=i;
                    starty=j;
                }
                else if(a[i][j]==0) empty++;
            }
        }
        dfs(a,startx,starty,0);
        return res;
    }
};