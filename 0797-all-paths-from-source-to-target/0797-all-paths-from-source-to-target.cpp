class Solution {
public:
    //time O(N*2^N)
    //space O(N*2^N)
    void dfs(vector<vector<int>> &a,vector<vector<int>>&res,vector<int>path,int cur_node){
        path.push_back(cur_node);
        if(cur_node==a.size()-1)
            res.push_back(path);
        else{
            for(auto child_node : a[cur_node])
                dfs(a,res,path,child_node);
        }
        path.pop_back();
            
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& a) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(a,res,path,0);
        return res;
    }
};