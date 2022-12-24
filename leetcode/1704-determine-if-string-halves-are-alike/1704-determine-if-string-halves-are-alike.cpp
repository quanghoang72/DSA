class Solution {
public:
    bool hasVowel(char s){
        return s=='a' || s=='e' || s=='i' || s=='o' || s=='u' ||
                s=='A' || s=='E' || s=='I' || s=='O' || s=='U';
    }
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(hasVowel(s[i])) cnt1++;
            if(hasVowel(s[n-i-1])) cnt2++;
        }
        return cnt1==cnt2;
    }
};