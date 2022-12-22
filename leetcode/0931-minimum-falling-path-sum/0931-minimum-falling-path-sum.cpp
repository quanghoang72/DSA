class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int res=INT_MAX;
        int r=a.size();
        int c=a[0].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                //min more than 2 element use {1,2,3,4,... }
               a[i][j]+=min({a[i-1][j],a[i-1][max(j-1,0)],a[i-1][min(j+1,c-1)]});
            }
        }
        return *min_element(a[r-1].begin(),a[r-1].end());
    }
};