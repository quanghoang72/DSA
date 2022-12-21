class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int start=0,count=0;
        int i=0,j=0;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            if(count) s[j++]=' '; //there is a complete word then add a space
            start=j;
            while(i<n && s[i]!=' ') {s[j++]=s[i++];}
            reverse(s.begin() + start,s.begin()+j);
            count++;
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        return s;
    }
};
