class Solution {
public:
    //time O(n^2 + E)
    //space O(V+E)
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> cities(n);
        for(auto v: roads){
            cities[v[0]].insert(v[1]);
            cities[v[1]].insert(v[0]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int connection= cities[i].size()+cities[j].size();
                if(cities[i].count(j))
                    connection-=1;
                res=max(res,connection);
            }
        }
        return res;
    }
};
