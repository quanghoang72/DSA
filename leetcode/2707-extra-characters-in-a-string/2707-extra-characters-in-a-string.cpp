struct TrieNode
{
    bool isEnd;
    TrieNode* map[26];
    TrieNode(){
        isEnd=0;
        fill(map,map+26,(TrieNode*)NULL);
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(vector<string>&dictionary){
        root=new TrieNode();
        for(auto &word: dictionary){
            TrieNode* cur=root;
            for(auto &c: word){
                int idx=c-'a';
                if(cur->map[idx]==NULL)
                    cur->map[idx]=new TrieNode();
                cur=cur->map[idx];
            }
            cur->isEnd=1;
        }
    }

    
};
class Solution {
public:
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
        int res=0;
        Trie trie(dictionary);
        dp=vector<int>(s.size(),s.size());
        return dfs(0,trie,s);
    }
    int dfs(int i,Trie &trie, string &s){
        if (i==s.size())
            return 0;
        if(dp[i]!=s.size())
            return dp[i];
        TrieNode* root=trie.root;
        int res=dfs(i+1,trie,s)+1;
        for(int j=i;j<s.size();j++){
            if (root->map[s[j]-'a']==NULL)
                break;
            root=root->map[s[j]-'a'];
            if(root->isEnd==1)
                res=min(res,dfs(j+1,trie,s));
        }
        dp[i]=res;
        return res;
    }
};