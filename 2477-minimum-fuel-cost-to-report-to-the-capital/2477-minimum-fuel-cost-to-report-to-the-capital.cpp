class Solution {
public:
    //time O(n)
    //space O(n)
    long long dfs(vector<vector<int>> &g,int k,int node, int pre,long long &res){
        long long people=1;
        for(auto &e : g[node]){
            if(e!=pre){ //avoid re-visited
                people+=dfs(g,k,e,node,res);
            }
        }
        //fuel comsumption needed from child to parent node
        // = number of cars (representatives / seats) * 1 (moving cost among city)
        if(node != 0) res+=ceil(people*1.0/k);
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& a, int k) {
        if(a.size()==0) return 0;
        long long res=0;
        int n=a.size()+1;
        vector<vector<int>> g(n);
        for(auto &e : a){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g,k,0,-1,res);
        return res;
    }
};