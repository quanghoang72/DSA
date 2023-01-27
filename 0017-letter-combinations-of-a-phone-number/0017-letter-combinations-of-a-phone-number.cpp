class Solution {
public:
    void backtrack(string &a,int n,vector<string> &s,string cur,int idx,vector<string> &res){
        if(idx==n){
            res.push_back(cur);
            return;
        }
        int digit=(a[idx]-'0');
        int sz=s[digit].size();
        for(int i=0;i<sz;i++){
            cur.push_back(s[digit][i]);
            backtrack(a,n,s,cur,idx+1,res);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string a) {
        if(a.size()==0) return {};
        vector<string> s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=a.size();
        vector<string> res;
        backtrack(a,n,s,"",0,res);
        return res;
    }
};