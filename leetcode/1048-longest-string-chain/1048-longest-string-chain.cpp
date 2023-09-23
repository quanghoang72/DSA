class Solution {
public:
    //time O(n^2)
    //space O(n)
    int n;
    vector<int> dp;
    int longestStrChain(vector<string>& words) {
        n=words.size();
        int res=1;
        dp=vector<int>(n,1);
        for(int i=0;i<n;i++){
            res=max(res,dfs(i,words)+1);
        }
        return res;
    }
    int dfs(int i,vector<string>& words){
        if(dp[i]!=1){
            return dp[i];
        }
        int sz=words[i].size();
        int res=0;
        for(int j=0;j<n;j++){
            if(sz+1==words[j].size() && isPredecessor(words[i],words[j])){
                res=max(res,dfs(j,words)+1);
            }
        }
        dp[i]=res;
        return res;
    }
    bool isPredecessor(string& pattern,string &s){
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==pattern[idx])
                idx++;
        }   
        return idx==pattern.size()? 1 :0;
    }
};