
class Solution {
public:
    //time O(n)
    //space O(26*n)
    vector<int> res;
    vector<int> dfs(vector<vector<int>> &g,string &labels, int node, int pre){
        int val=1;
        vector<int> temp(26,0);
        vector<int> ret(26);
        for(int cur:g[node]){
            if(cur!=pre){
                temp=dfs(g,labels,cur,node);
                if(temp[labels[node]-'a']>0)
                    val+=temp[labels[node]-'a'];
            }
            //adding new value to table through every node in same branch
            for(int i=0;i<26;i++){
                ret[i]+=temp[i];
            }
            ret[labels[node]-'a']=val; //assign-replace value in the alphabet vector
            res[node]=val; //result 
        }
        return ret;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        res=vector<int>(n);
        
        vector<vector<int>> g(n);
        //construct graph nodes
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(g,labels,0,-1);
        return res;
    }
};