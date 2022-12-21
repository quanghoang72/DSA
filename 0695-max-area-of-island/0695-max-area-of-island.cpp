class Solution {
public:
    int area(vector<vector<int>> &a,int r,int c,int x,int y){
        int cnt=1;
        if(x < 0 || x>= r)  return 0;
        if( y<0 || y>=c) return 0;
        if(a[x][y]==0) return 0;

        a[x][y]=0; //visited

        cnt+=area(a,r,c,x+1,y);
        cnt+=area(a,r,c,x-1,y);
        cnt+=area(a,r,c,x,y-1);
        cnt+=area(a,r,c,x,y+1);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int res=0;
        int r=a.size();
        int c=a[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1)
                    res=max(res,area(a,r,c,i,j));
            }
        }
        return res;
    }
};
