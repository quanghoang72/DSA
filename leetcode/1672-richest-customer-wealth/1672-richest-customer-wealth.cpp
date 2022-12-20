class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int r=a.size();
        int res=0;
        int localSum=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<a[i].size();j++){
                localSum+=a[i][j];
            }
        res=max(res,localSum);
        localSum=0;
        }
        return res;
    }
};