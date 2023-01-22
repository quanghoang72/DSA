class Solution {
public:
    //time O(n^2)
    //space O(1)
    //linear scan every character in string s
    //use 2 pointer to expand left-right from that middle character and check palindrome of that substr
    string longestPalindrome(string s) {
        int maxlength=1;
        int start=0;
        for(int i=0;i<s.size();i++){
            palindromeExpand(s,i,i,maxlength,start); //check for odd length (there is a character in the middle of string)
            palindromeExpand(s,i,i+1,maxlength,start); //check even length string (no character in the middle)
        }
        return s.substr(start,maxlength);
    }
    
    void palindromeExpand(string &s,int l,int r,int &maxlength,int &start){
        while(l>=0 && r <s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        if(r-l-1 > maxlength){
            maxlength=r-l-1; //update greater length
            start=l+1; //because left decreased one more prior to exit the loop
        }
    }
};