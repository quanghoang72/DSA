class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
        int m = size(a), n = size(a[0]), total = m * n;
        if(r * c != total) return a;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < total; i++) 
            ans[i / c][i % c] = a[i / n][i % n];
        return ans;
    }
};