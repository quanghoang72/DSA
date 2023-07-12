class Solution {
public:
    //time O(n)
    //space O(n)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        //find terminal nodes
        vector<bool> terminal(n);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0)
                terminal[i]=1;
        }
        
        //run dfs on unknown node
        for(int i=0;i<n;i++){
            if(terminal[i]){
                continue;
            } 
            vector<bool> vis(n);
            dfs(graph,terminal,vis,i);    
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(terminal[i])
                res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int>> &graph, vector<bool> &terminal,vector<bool> &vis,int cur){
        //reach terminal node
        if(terminal[cur])
            return 1;
        
        //loop detect or visited node
        if(vis[cur]) 
            return 0;
        vis[cur]=1;
        
        int edge=graph[cur].size();
        for(auto nei: graph[cur]){
            bool next=dfs(graph,terminal,vis,nei);
            if(!next){
                return 0;
            }
            else{
                edge--;
                // assign neighbor node is safe if dfs on next node is safe
                terminal[nei]=1;
            }
        }
        
        //if every possible out-degree edges is safe, determine current node is safe
        if(edge==0) terminal[cur]=1;
        
        return !edge; 
    }
};