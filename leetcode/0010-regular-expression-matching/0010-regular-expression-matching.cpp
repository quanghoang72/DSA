// class Solution {
// public:
//      //recursive TLE
//      //time O(2^n) n is psize
//      //space O(1)
//     bool dfs(int i,int j,string &s, string &p){
//         if(i >=s.size() && j>=p.size()) return true;
//         if(j>=p.size()) return false;
//         bool match=(i<s.size())&&(s[i]==p[j] || p[j]=='.');
//         if(j+1<p.size() && p[j+1]=='*'){
//             retrun dfs(i,j+2,s,p) || (match && dfs(i+1,j,s,p)); 
//         }
//         if(match){
//             return dfs(i+1,j+1,s,p);
//         }
//         return false;
//     }
//     bool isMatch(string s, string p) {
//         return dfs(0,0,s,p);
//     }
// };
class Solution {
public:
    //time O(n*m)
    //space O(n*m)
    bool isMatch(string s, string p) {
        //"*" can be 0,1,2,3,... duplicate previous character
        int m=s.size(),n=p.size();
        vector<vector<bool>> v(m+1,vector<bool>(n+1)); //dp 2-d
        v[0][0]=1; //empty string vs empty pattern
        
        //first row (empty string vs pattern)
        for(int i=1;i<=n;i++){
            //skip the first character
            //if the current character is "*" then the current string is identical with current pattern -2
            //(ba*)=(b)
            //remove the "*" and previous character
            v[0][i]= i>1 && p[i-1]=='*' && v[0][i-2];
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //if match character or pattern is '.'
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    v[i][j]=v[i-1][j-1]; //diagonal (both character can be removed)
                
                else if(p[j-1]=='*'){
                    //current pattern -2 OR
                    //if the charac before "*" match with string s || pattern is "." -->
                    //remove 1 character from s
                    v[i][j]=v[i][j-2] || (v[i-1][j] && (p[j-2]==s[i-1] || p[j-2]=='.'));
                }
                else
                    v[i][j]=0;
            }
        }
        return v[m][n];
    }
};