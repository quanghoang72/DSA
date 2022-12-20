class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph;
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector <bool> visited(n,0);
        stack<int> s;
        s.push(start);
        visited[start]=1;
        while(!s.empty()){
            auto top=s.top();
            if(top==end)return 1;
            s.pop();
            for(auto node : graph[top]){
                if(!visited[node]){
                    visited[node]=1;
                    s.push(node);
                }
            }
        }
        return false;
    }
};