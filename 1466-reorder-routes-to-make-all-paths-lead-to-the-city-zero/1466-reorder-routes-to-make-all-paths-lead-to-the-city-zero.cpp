class Solution {
public:
    //time O(n)
    //space O(n)
    
    //traverse from 0 node so every direction that is opposite to that direction will be negative
    int minReorder(int n, vector<vector<int>>& a) {
        vector<vector<int>> g(n);
        for(auto &node : a){
            int u=node[0];
            int v=node[1];
            g[u].push_back(v);
            g[v].push_back(-u);
        }
        int res=0;
        vector<bool> visited(n);
        dfs(0,g,res,visited); 
        return res;
    }
    void dfs(int cur,vector<vector<int>> &g,int &res,vector<bool> &visited) {
        visited[cur]=1;
        for(auto &node : g[cur]){
            if(!visited[abs(node)]) {
                if(node>0) res++;
                dfs(abs(node),g,res,visited);
            }
        }
    }
};