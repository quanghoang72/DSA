class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        vector<int> dir={-1,0,1,0,-1}; //direction
        int r=a.size();
        int c=a[0].size();
        
        //bfs store cordinate x-y
        queue<pair<int,int>> q;
            
        int res=-1;
        int fresh=0; //count all fresh oranges
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==2){
                    q.push({i,j});
                }
                else if(a[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto rotten=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=rotten.first + dir[i];
                    int nc=rotten.second + dir[i+1];
                    if(nr < 0 || nc < 0 || nr >=r || nc >= c || a[nr][nc]==0 || a[nr][nc]==2) continue;
                    a[nr][nc]=2;
                    q.push({nr,nc});
                    fresh--; 
                }
            }
            //the rotten have just spread the rot to 4-direc fresh oranges 
            res++; //increase by 1 min
        }
        if(fresh>0) return -1; //remain fresh oranges;
        //if there is no orange return 0
        return res==-1 ? 0 : res;
    }
};

