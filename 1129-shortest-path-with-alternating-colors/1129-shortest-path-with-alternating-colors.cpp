class Solution {
public:
    //time O(n)
    //space O(n)
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<int> res(n,-1);

        vector<vector<pair<int,int>>> g(n);
        //construct adjacent list
        for(auto &e : r){
            g[e[0]].push_back({e[1],2});
        }
        for(auto &e : b){
            g[e[0]].push_back({e[1],1});
        }

        queue<vector<int>> q;
        q.push({0,0,-1}); //cur_node , distance, previous_color
        while(!q.empty()){
            int cur=q.front()[0];
            int dis=q.front()[1];
            int color=q.front()[2];
            q.pop();
            //the first iteration always get the shorest path (assign when distance=-1)
            //no need to update again.
            res[cur]= res[cur]==-1 ? dis : res[cur];
            for(auto &i : g[cur]){
                if(i.first != -1 && i.second!=color){
                    q.push({i.first,dis+1,i.second});
                    i.first=-1;
                }
            }
        }  
        return res;
    }
};