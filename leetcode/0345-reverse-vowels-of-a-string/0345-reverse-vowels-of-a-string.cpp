class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='A' || c=='E' || c=='e' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U';
    }

    string reverseVowels(string s){
        int n=s.size();
        int last=n-1;
        int first=0;
        while(first < last){
            while(!isVowel(s[first]) && first < last){
                first++;
            }
            while(!isVowel(s[last]) && last > first){
                last--;
            }
            if(isVowel(s[first]) && isVowel(s[last]) && first < last){
                swap(s[first],s[last]);
                first++;
                last--;
            }
        }
        return s;
    }
};