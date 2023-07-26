class Solution {
public:
    //time O(logn)
    //space O(1)
    int peakIndexInMountainArray(vector<int>& a) {
        int l=0,r=a.size()-1;
        while (l<r){
            int m=l+(r-l)/2;
            if(a[m]>a[m+1])
                r=m;
            else
                l=m+1;
        }
        return l;
    }
};