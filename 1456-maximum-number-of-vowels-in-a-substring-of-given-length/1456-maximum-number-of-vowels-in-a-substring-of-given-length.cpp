class Solution {
public:
    //time O(n)
    //space O(1)
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' ||  c=='o' ||  c=='u';
    }
    int maxVowels(string s, int k) {
        int window=0;
        int res=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isVowel(c)) window++;
            if(i>=k-1){
                res=max(res,window);
                if(isVowel(s[l++])) window--;
            }
        }
        return res;
    }
};