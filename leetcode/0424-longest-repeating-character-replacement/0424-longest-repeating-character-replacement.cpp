class Solution {
public:
    //k operation is limited
    //so to use least k times we have to get the length of the current window
    //minus the most frequence character in that window
    // window length - maxf = other charac that need to be changed (k) 
    
    // time O(n) 
    // space O(26)
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        //to get the maximum value of freq
        int maxf=0;
        int res=0;
        
        //point at the start of the window
        int l=0;
        for(int i=0;i<s.size();i++){
            count[s[i]-'A']++;
            maxf=max(maxf,count[s[i]-'A']);
 
            // invalid window
            // the length of current window contains more character need to be changed K time
            while((i-l+1)-maxf > k){
                count[s[l]-'A']--; //remove the first char
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};