
class Solution {
public:
    bool dfs(vector<vector<char>>& a, string w,int i,int x,int y){
        if(i==w.length()) return true;
        if(x<0 || y <0 || x>=a.size() || y>=a[x].size() || a[x][y]!=w[i]) return false;
        char tmp=a[x][y];
        a[x][y]='_';
        bool res= dfs(a,w,i+1,x+1,y) || dfs(a,w,i+1,x-1,y) || dfs(a,w,i+1,x,y+1) || dfs(a,w,i+1,x,y-1);
        a[x][y]=tmp;
        return res;
    }
    bool exist(vector<vector<char>>& a, string w) {
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(dfs(a,w,0,i,j)) 
                    return true;
            }
        }
        return false;
    }
};