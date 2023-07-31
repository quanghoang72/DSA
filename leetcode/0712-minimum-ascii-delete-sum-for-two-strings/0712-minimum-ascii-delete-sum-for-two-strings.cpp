class Solution {
public:
    //time O(n*m)
    //space O(n*m)
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>prefixS1(n+1);
        vector<int>prefixS2(m+1);
        for(int i=1;i<=n;i++){
            prefixS1[i]=(int)s1[i-1]+prefixS1[i-1];
        }
        for(int i=1;i<=m;i++){
            prefixS2[i]=(int)s2[i-1]+prefixS2[i-1];
        }
        vector<vector<int>> mem(n+1,vector<int> (m+1,-1));
        return dfs(s1,s2,0,0,n,m,mem,prefixS1,prefixS2);
    }
    int dfs(string &s1,string &s2,int i,int j,int n,int m,vector<vector<int>>&mem,vector<int>&prefixS1,vector<int>&prefixS2){
            if(mem[i][j]!=-1)
                return mem[i][j];
            if(i==n && j==m)
                return mem[i][j]=0;
            if(i==n){
                return mem[i][j]=prefixS2[m]-prefixS2[j];
            }
            if(j==m){
                return mem[i][j]=prefixS1[n]-prefixS1[i];
            }
            if(s1[i]==s2[j])
                return mem[i][j]=dfs(s1,s2,i+1,j+1,n,m,mem,prefixS1,prefixS2);
            else{
                return mem[i][j]=min(
                            s1[i]+dfs(s1,s2,i+1,j,n,m,mem,prefixS1,prefixS2),
                            s2[j]+dfs(s1,s2,i,j+1,n,m,mem,prefixS1,prefixS2));
            }
    }
};