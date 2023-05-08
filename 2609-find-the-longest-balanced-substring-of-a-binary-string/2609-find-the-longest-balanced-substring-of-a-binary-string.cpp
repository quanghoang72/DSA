class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res=0;
        int n=s.size();
        int zeros=0;
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zeros= ones ? 1 : zeros+1;
            }
            ones = s[i]=='0' ? 0 : ones+1;
            res = max(res, 2 * min(zeros, ones));
        }
        return res;
    }
};