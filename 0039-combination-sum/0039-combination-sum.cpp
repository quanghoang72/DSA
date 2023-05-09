class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(a,0,0,k,cur,res);
        return res;
    }
    void backtrack(vector<int> &a,int idx,int sum,int k,vector<int> &cur,vector<vector<int>> &res){
        if(sum>k) return ;
        if(sum==k){
            res.push_back(cur);
            return;
        }
        for(int i=idx;i<a.size();i++){
            if(sum+a[i] > k) return;
            cur.push_back(a[i]);
            backtrack(a,i,sum+a[i],k,cur,res);
            cur.pop_back();
        }
    }
};