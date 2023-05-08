class Solution {
public:
    //time O(n)
    //space O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int res=0;
        for(int i=0;i<n;i++){
            res+=mat[i][i];
            res+=mat[i][n-1-i];
        }
        if(n%2)
            return res-mat[n/2][n/2];
        return res;
    }
};