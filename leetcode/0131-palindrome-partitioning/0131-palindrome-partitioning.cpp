class Solution {
public:
    bool isPalindrome(string &s,int end, int start){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void backtrack(string &s,vector<vector<string>> &res,int i,vector<string> &temp){
        if(i==s.size()){
            res.push_back(temp);
            return;
        }
        for(int idx=i;idx<s.size();idx++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(i,idx-i+1));
                backtrack(s,res,idx+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> res;
         vector<string> temp;
         backtrack(s,res,0,temp);
         return res;
    }
};