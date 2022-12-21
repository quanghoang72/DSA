class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int v=1;
        int i=0;
        while(v<=n*n){
            //left to right
            int j=i;
            while(j<n-i){
                res[i][j++]=v++;
            }
            //top to down
            j=i+1;
            while(j<n-i){
                res[j++][n-i-1]=v++;
            }
            //right to left
            j=n-i-2;
            while(j>i){
                res[n-i-1][j--]=v++;
            }
            j=n-1-i;
            while(j>i){
                res[j--][i]=v++;
            }
            i++;
        }
        return res;
    }
};