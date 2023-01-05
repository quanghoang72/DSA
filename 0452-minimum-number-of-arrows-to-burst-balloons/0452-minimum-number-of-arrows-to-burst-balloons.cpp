class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](const auto &a, const auto &b){
            return a[1] < b[1];
        });
        int res=1;
        int prev=a[0][1];
        for(int i=1;i<a.size();i++){
            if(a[i][0]>prev){
                res++;
                prev=a[i][1];
            }
        }
        return res;
    }
};