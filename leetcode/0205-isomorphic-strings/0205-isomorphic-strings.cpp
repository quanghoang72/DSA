class Solution {
public:
    bool helper(string s,string t) {
        unordered_map <char,char> res;
        for(int i=0;i<s.size();i++) {
            if(res.find(s[i])!=res.end()) {
                if(res[s[i]]!=t[i]) return false;
            }
            else {
                res[s[i]]=t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
};