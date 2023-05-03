class Graph {
public:
    vector<vector<pair<int,int>>> g;
    Graph(int n, vector<vector<int>>& a) {
        g.resize(n);
        for(auto edge:a){
            g[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int src, int dst) {
        int n=g.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(node==dst) return cost;
            if(cost > dist[node]) continue;
            for(auto nei : g[node]){
                int newDistance=cost + nei.second;
                if(newDistance < dist[nei.first]){
                    dist[nei.first]=newDistance;
                    pq.push({newDistance,nei.first});
                }
            }
        }
        return -1;
    }
};

