class Solution {
public:
    //time O(nm)
    //space O(nm)
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> sum(n+1,vector<int> (m+1));
        //calculate the prefix blocking sum of 2d array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=mat[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r1=max(0,i-k);
                int c1=max(0,j-k);
                int r2=min(n-1,i+k);
                int c2=min(m-1,j+k);
                r1++;c1++;r2++;c2++; //prefix sum start from 1,1
                res[i][j]=sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
            }
        }
        return res;
    }
};