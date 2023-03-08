class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int l=0;
        int r=a.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int backw=m-1 >=0 ? a[m-1] : INT_MIN;
            int forw=m+1 < a.size() ? a[m+1] : INT_MIN;
            if(a[m] >= backw && a[m] >= forw) return m;
            else if(a[m] >= backw) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};