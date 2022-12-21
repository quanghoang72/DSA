class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        vector<int> pre=a[0];
        int res=0;
        for(int i=1;i<n;i++){
            vector<int> tmp=a[i];
            if(pre[1]>tmp[0]){
                res++;
            }
            else pre=a[i];
        }
        return res;
    }
};