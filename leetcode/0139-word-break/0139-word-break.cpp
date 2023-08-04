class Solution {
public:
    // N=s.size , M=wordDict.size
    //time O(N^3 * M)
    //space O(N^2 + M)
    unordered_map<string,bool> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        return dfs(s,wordSet,mp);
    }
    bool dfs(string s,unordered_set<string>& wordSet,unordered_map<string,bool> &mp){
        if(wordSet.find(s)!=wordSet.end())
            return 1;
        if(mp.find(s)!=mp.end())
            return mp[s];
        for(int i=1;i<s.size();i++){
            string prefix=s.substr(0,i);
            if(wordSet.find(prefix)!=wordSet.end() && dfs(s.substr(i),wordSet,mp))
                return mp[s]=1;
        }
        return mp[s]=0;
    }
};