class Solution {
public:
    int dir[5]={0,-1,0,1,0};
    bool check_constraint (int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    bool check_boundary (int i, int j, int m, int n){        
        return (i == 0 || i == m-1 || j == 0 || j == n-1);
    }

    int nearestExit(vector<vector<char>>& a, vector<int>& entrance) {
        int r=a.size();
        int c=a[0].size();
        queue<array<int,3>>q;
        q.push({entrance[0],entrance[1],0});
        while(!q.empty()){
            auto [i,j,step]=q.front(); q.pop();
            if(check_boundary(i,j,r,c) && (i!=entrance[0] || j!=entrance[1]))
                return step;
            for(int d=0;d<4;d++){
                int nr=i+dir[d];
                int nc=j+dir[d+1];
                if(check_constraint(nr,nc,r,c) && a[nr][nc]=='.'){
                    a[nr][nc]='+'; //visited
                    q.push({nr,nc,step+1});
                }
            }
            
        }
        return -1;
    }
};