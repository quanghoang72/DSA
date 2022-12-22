class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        //create 2 2d maxtrix to store length
        //for each substring
        // i+1 and j+1 to avoid the first empty character for both string which initiallize as 0
        // if 2 char doesnot match, looking for max match length by del 1 char from a or 1 from b 
        // else +1 to length
        short x[1001][1001];
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                x[i+1][j+1]= a[i]==b[j] ? 1+x[i][j] : max(x[i+1][j],x[i][j+1]);
            }
        }
        return x[a.size()][b.size()];
    }
};