class Solution {
public:
    //time O(n)
    //space O(n)
    
    int res=-1;
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> visited(n);
        for(int i=0;i<edges.size();i++){
            if(!visited[i]){
                vector<int> v; //extra visited vector of current dfs to avoid repeating visited node
                dfs(edges,i,v,visited);
            }
        }
        return res;
    }
    void dfs(vector<int> &edges,int cur,vector<int> &v,vector<bool> &visited){
        if(cur==-1) return;
        if(visited[cur]){ //cycle detect
            int count=-1; 
            //find seen node in the extra vector
            for(int i=0;i<v.size();i++){
                if(v[i]==cur)
                {
                    count=i;
                    break;
                }
            }

            if(count==-1) return; //cant find repetitive (starting) node

            int sizeOfCycle= v.size() - count;
            res=max(res,sizeOfCycle);
            return; 
        }
        visited[cur]=1;;
        v.push_back(cur);
        dfs(edges,edges[cur],v,visited);
    }
};