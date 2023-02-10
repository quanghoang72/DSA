class Solution {
public:
    //time O(n^2)
    //space O(n)
    
    //bfs multi source
    int maxDistance(vector<vector<int>>& a) {
        int n=a.size();
        int res=-1;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j])
                    q.push({i,j}); //add all land to queue
            }
        }
        int direc[5]={0,1,0,-1,0};
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            res=a[x][y]; //the last cell is also the farthest distance to water
            for(int i=0;i<4;i++){
                int nr=x+direc[i];
                int nc=y+direc[i+1];
                if(min(nr,nc) >=0 && max(nr,nc)<n && a[nr][nc]==0){
                    a[nr][nc]=a[x][y]+1; //add 1 to distance and mark visited
                    q.push({nr,nc});
                }
            }
        }
        return res>1  ? res-1 : -1;
    }
};