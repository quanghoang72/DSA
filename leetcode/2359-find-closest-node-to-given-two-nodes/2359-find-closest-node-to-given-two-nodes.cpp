class Solution {
public:
    //time O(n)
    //space O(n)
    void dfs(vector<int>&a,int node,vector<int> &dist,vector<bool> &visited){
        visited[node]=1;
        int near=a[node];
        //check if neighbour node is not visited and exist
        if(near==-1 || visited[near]==true) return;
        dist[near]=dist[node]+1;
        dfs(a,near,dist,visited);
    }
    int closestMeetingNode(vector<int>& a, int node1, int node2) {
        int n=a.size();
        vector<int> dist1(n,0);
        vector<int> dist2(n,0);
        vector<bool> visited1(n,0);
        vector<bool> visited2(n,0);
        //construct a distance graph for every node from starting node
        dfs(a,node1,dist1,visited1);
        dfs(a,node2,dist2,visited2);
        
        int mindist=INT_MAX;
        int res=-1;
        for(int i=0;i<n;i++){
            //the collision node must be visited by both start
            //if there is a common node with less distance
            //update result
            if(visited1[i]==true && visited2[i]==true && mindist>max(dist1[i],dist2[i]) ){
                mindist=max(dist1[i],dist2[i]);
                res=i;
            }
        }
        return res;
    }
};

