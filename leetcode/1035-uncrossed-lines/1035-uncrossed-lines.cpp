class Solution {
public:
    //time O(n*m)
    //space O(m)
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n =a.size();
        int m= b.size();
        vector<int> prev(m+1);
        for(int i=1;i<=n;i++){
            vector<int> cur(m+1);
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1])
                    cur[j]=1+prev[j-1];
                else
                    cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};