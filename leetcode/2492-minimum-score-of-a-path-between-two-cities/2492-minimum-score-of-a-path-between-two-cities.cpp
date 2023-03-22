class Solution {
public:
    //time O(mlogn) 
    //m : edges, n: vertices
    //space O(n)
    vector<int> parent;
    vector<int> size;
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int minScore(int n, vector<vector<int>>& a) {
        parent=vector<int>(n+1);
        size=vector<int>(n+1);
            for(int i=1;i<=n;i++){
                parent[i]=i;
                size[i]=0;
            }
            for(auto &road : a){
                union_sets(road[0],road[1]);
            }
            int res=INT_MAX;
                        int root=find_set(1);
            for(auto &road:a){
    
                int parent1=find_set(road[0]);
                int parent2=find_set(road[1]);
                if(root==parent1 && parent1==parent2){
                    res=min(res,road[2]);
                }
            }
            return res;

        //time O(n)
        //space O(n)
        // vector<int> visited(n+1);
        // int res=INT_MAX;
        // vector<vector<pair<int,int>>> graph(n+1);
        // for(auto &road:a){
        //     int start=road[0];
        //     int des=road[1];
        //     int cost=road[2];
        //     graph[start].push_back({des,cost});
        //     graph[des].push_back({start,cost});
        // }
        // queue<int> q;
        // q.push(1);
        // visited[1]=1;
        // while(!q.empty()){
        //     auto node = q.front();
        //     q.pop();
        //     for(int i=0;i<graph[node].size();i++){
        //         auto [next,nxtcost]=graph[node][i];
        //         if(!visited[next]){
        //             q.push(next);
        //             visited[next]=1;
        //         }
        //         res=min(res,nxtcost);
        //     }
        // }
        // return res;
        
    }
};
