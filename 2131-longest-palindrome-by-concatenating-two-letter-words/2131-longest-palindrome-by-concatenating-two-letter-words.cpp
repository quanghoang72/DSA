class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        //without hashmap
        // vector<vector<int>> v(26,vector<int>(26,0));
        // int ans=0;
        // for(string w : a){
        //     int a=w[0]-'a',b=w[1]-'a';
        //     if(v[b][a]){
        //         ans+=4;
        //         v[b][a]--;
        //     }
        //     else v[a][b]++;
        // }
        // for(int i=0;i<26;i++){
        //     if(v[i][i]) {ans+=2;break;}
        // }
        // return ans;

        //hashmap
        unordered_map<string,int> mp;
        int ans=0,same=0;
        for(string w: a){
            if(w[0]==w[1]){
                if(mp[w]){
                    mp[w]--;
                    same--;
                    ans+=4;
                }
                else{
                    same++;
                    mp[w]++;
                }
            }
            else{
                string rev=w;
                reverse(begin(rev),end(rev));
                if(mp[rev])
                {
                    ans+=4;
                    mp[rev]--;
                }
                else mp[w]++;
            }
        }
        return same ? ans + 2 : ans;
    }
};