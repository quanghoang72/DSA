class Solution {
public:
    //time O(V+E)
    //space O(V)
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            if (!bfs(i,1,g,a))
                return false;
        }   
        return true; 
    }
    bool bfs(int node,int val,vector<vector<int>>& g,vector<int> &a){
        if(a[node]){
            return true;
        }
        queue<int> q;
        q.push(node);
        a[node]=val;
        while(!q.empty()){
            int cur=q.front();
            int curVal=a[cur];
            q.pop();

            for(auto nei : g[cur]){
                if(a[nei]==0){
                    q.push(nei);
                    a[nei]=curVal*-1;
                }
                else{
                    if(a[nei]==a[cur])
                        return false;
                }
            }
        }
        return true;
    }
};