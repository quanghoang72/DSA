class Solution {
public:
    void backtrack(string &s,vector<string> &res,const int &i,int n){
        if(i==n){
            res.push_back(s);
            return;
        }
        backtrack(s,res,i+1,n);
        if(isalpha(s[i])){
            // ^ to transform from lower to upper and vice versa
            s[i]^=(1<<5); //+32 Ascii to uppercase when lower
            backtrack(s,res,i+1,n);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        vector<string> res;
        backtrack(s,res,0,n);
        return res;
    }
};
