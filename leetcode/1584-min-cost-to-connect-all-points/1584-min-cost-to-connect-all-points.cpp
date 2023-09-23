class Solution {
public:
    // time O(V*V)
    // spaceO(V)
    int minCostConnectPoints(vector<vector<int>>& p) {
        int res=0;
        int n=p.size();

        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;

        min_heap.push({0,0,n});
        
        while(!min_heap.empty()){
            int d=min_heap.top()[0];
            int idx=min_heap.top()[1];
            int prev=min_heap.top()[2];
            int x=p[idx][0],y=p[idx][1];
            min_heap.pop();
            if(d>dist[idx])
                continue;
            adj[prev].push_back({idx,d});

            int x_gap,y_gap,sum;
            for(int i=0;i<n;i++){
                if (i==idx)   
                    continue;
                x_gap=abs(x-p[i][0]);
                y_gap=abs(y-p[i][1]);
                sum=x_gap+y_gap;
                if(sum < dist[i]){
                    dist[i]=sum;
                    if(sum < dist[idx]){
                        dist[idx]=sum;
                    }
                    min_heap.push({sum,i,idx});
                }
            }
        }
        dfs(res,adj,0);
        return res;
    }
    void dfs(int &res,vector<vector<pair<int,int>>> &adj, int i){
        for(auto v:adj[i]){
            int nxt=v.first;
            int d=v.second;
            res+=d;
            dfs(res,adj,nxt);
        }
    }
};