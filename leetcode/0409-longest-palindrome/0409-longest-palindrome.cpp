class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128]={};
        //count freq of charac in s
        for(auto c:s) ++freq[c];
        //to count charac that appears ood times
        int Oddtimes = 0;
        for(auto i:freq) Oddtimes += i & 1;
        
        return s.size() - Oddtimes + (Oddtimes > 0);        
    }
};      