class Solution {
public:
    //time O(n)
    //space O(n)
    int ans=1;
    int dfs(vector<vector<int>> &g,string &s, int node){
        //no child node
        if(g[node].size()==0) return 1;
        
        //branch 1 and 2 to store the maximum value from each child node
        int branch1=0,branch2=0;
        for(auto &child : g[node]){
            int cur=dfs(g,s,child);
            
            if(s[child]==s[node]) continue; //skip same charac
            
            if(cur>branch1){
                branch2=branch1;
                branch1=cur;
            } 
            else 
                branch2=max(branch2,cur);
        }
        //sum of 2 child branch = longest path going through this node 
        //in the sub-tree rooted at this node
        //+1 for the current parent node
        ans=max(ans,1+branch1+branch2);
        
        //return value with longest path to parent node
        return 1+branch1;
    }
    int longestPath(vector<int>& a, string s) {
        int n=a.size();
        vector<vector<int>> g(n);
        //graph construct
        for(int i=1;i<a.size();i++){
            g[a[i]].push_back(i);
        }
        dfs(g,s,0);
        return ans;
    }
};