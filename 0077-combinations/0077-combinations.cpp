class Solution {
public:
    void backtrack(int n,int k,vector<vector<int>> &res,vector<int> &temp,const int &start, const int &idx){
        if(idx==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp[idx]=i;
            backtrack(n,k,res,temp,i+1,idx+1);
        }
    }
    vector<vector<int>> combine(int n,int k) {
        vector<vector<int>> res;
        vector<int> temp(k);
        backtrack(n,k,res,temp,1,0);
        return res;
    }
};

