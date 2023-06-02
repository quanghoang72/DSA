class Solution {
public:
    //time O(n^2)
    //space O(n)
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res=1;
        int n=bombs.size();
        vector<vector<int>> mp (n);
        for(int i=0;i<n;i++){
            int x=bombs[i][0];
            int y=bombs[i][1];
            int r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int a=bombs[j][0];
                int b=bombs[j][1];
                if(isInclude(x,y,r,a,b))
                    mp[i].push_back(j);
            }
        }
        
        for(int i=0;i<n;i++){
            vector<int> visited(n);
            res=max(res,dfs(i,mp,visited));
        }
        return res;
    }
    bool isInclude(int x,int y,int r,int i,int j){
        return sqrt((long long)(x-i)*(x-i) + (long long)(y-j)*(y-j)) <= r;
    }
    int dfs(int cur,vector<vector<int>>& mp,vector<int> &visit){
        int res=1;
        visit[cur]=1;

        for(auto nei : mp[cur]){
            if(!visit[nei])
                res+=dfs(nei,mp,visit);
        }
        return res;
    }
};


