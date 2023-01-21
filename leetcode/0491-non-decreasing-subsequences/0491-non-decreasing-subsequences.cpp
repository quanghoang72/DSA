class Solution {
public:
    void backtrack(set<vector<int>> &res,vector<int>&a,vector<int>&tmp,int i){
        if(i>=a.size()){
            if(tmp.size()>=2)res.insert(tmp); 
            return;
        }
        if(tmp.empty() || a[i]>=tmp.back()){
            tmp.push_back(a[i]);
            backtrack(res,a,tmp,i+1);
            tmp.pop_back();
        }
        backtrack(res,a,tmp,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& a) {
        if(a.size()<=1) return {};
        vector<int> tmp;
        set<vector<int>> res;
        backtrack(res,a,tmp,0);
        return vector(res.begin(),res.end());
    }
};