class Solution {
public:
    vector<vector<int>> v;
    //v graph nodes

    vector<int> counter, res;
    //counter used to count the number of nodes in each subtree

    void dfs(int i, int p = -1) {
        //traverse to child nodes of current root
        //else if node is leaf then count itself =1
        for(auto u : v[i]) {
            if(u == p) continue; //skip previous seen node
            dfs(u, i);
            //accumulate the adjacent nodes
            counter[i] += counter[u];
            //adding the number of nodes of subtree 
            //because every node in subtree will be 1 unit more far from the original root.
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            //when re-rooting there are count[u] nodes are closer and n-count[u] are further
            //res[u] = baseroot(parent i) - closernodes + furthernodes( = n-closernodes)
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);

        //create v graph for connect nodes
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        //first dfs to count number of nodes
        dfs(0);
        //second to calculate sum of distance
        dfs2(0, n);
        return res;
    }
};