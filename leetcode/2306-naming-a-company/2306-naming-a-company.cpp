class Solution {
public:
    //time O(n)
    //space O(n)
    long long distinctNames(vector<string>& a) {
        vector<unordered_set<string>> mp(26);
        long long res=0;
        
        //goup word by first character to prevent swapping 2 word have same first letter
        //key = first character
        //value = substring
        for(string &w : a){
            mp[w[0]-'a'].insert(w.substr(1,w.size()-1));
        }
        
        //avoid same prefix
        for(int i=0;i<26;i++){
            if(mp[i].size()==0) continue;
            
            for(int j=i+1;j<26;j++){
                if(mp[j].size()==0) continue;
                
                int match=0; //count same prefix word
                for(auto &w:mp[i]){
                    if(mp[j].count(w)) match++;
                }
                
                //*2 for each pair distinct valid word
                res+=2*(mp[i].size()-match)*(mp[j].size()-match);
            }
        }
        return res;
    }
};