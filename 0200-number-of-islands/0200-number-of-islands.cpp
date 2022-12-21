class Solution {
public:
    void count(vector<vector<char>>&a,int r,int c,int x,int y){
        if(x <0 || x >= r) return;
        if(y<0 || y >= c) return; 
        if(a[x][y]=='0') return;
        a[x][y]='0';
        count(a,r,c,x+1,y);
        count(a,r,c,x-1,y);
        count(a,r,c,x,y+1);
        count(a,r,c,x,y-1);  
    }
    
    int numIslands(vector<vector<char>>& a) {
        int res=0;
        int r=a.size();
        int c=a[0].size();
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j]=='1'){
                    count(a,r,c,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
