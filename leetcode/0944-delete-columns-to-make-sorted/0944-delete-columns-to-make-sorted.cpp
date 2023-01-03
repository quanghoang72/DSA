class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int res=0;
        for(int j=0;j<a[0].size();j++){
            for(int i=1;i<a.size();i++){
                if(a[i][j]<a[i-1][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};