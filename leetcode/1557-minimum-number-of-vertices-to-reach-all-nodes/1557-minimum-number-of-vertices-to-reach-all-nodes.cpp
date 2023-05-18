class Solution {
public:
    //time O(V+E)
    //space O(E)
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for(auto e:edges){
            indegree[e[1]]=1;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!indegree[i]) res.push_back(i);
        }
        return res;
    }
};