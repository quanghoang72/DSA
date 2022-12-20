class Solution {
public:
    bool canConstruct(string a, string b) {
        if(b.size()<a.size()) return false;
        map<char,int>mp;
         for(char c : b) {
            mp[c]++;
        }
        
        for(int i=0; i<a.length(); i++) {
            if(mp[a[i]]>0) mp[a[i]]--;
            else return false;
        }
        
        return true;
    }
};