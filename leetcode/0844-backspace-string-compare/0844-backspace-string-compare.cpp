class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int a=0,b=0;
        
        //adjust string s
        for(int i=0;i<s.size();i++){
            if(s[i]=='#') a=max(0,--a);
            else s[a++]=s[i];
        }
        //adjust string t
        for(int i=0;i<t.size();i++){
            if(t[i]=='#') b=max(0,--b);
            else t[b++]=t[i];
        }
        //a and b represent as idx of s and t
        if(a!=b) return false;
        else {
            for(int i=0;i<a;i++){
                if(s[i]!=t[i]) return false;
            }
        }
    return true;
    }
};