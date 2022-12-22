class Solution {
public:
    //time O(n)
    //space O(1)
    int trap(vector<int>& a) {
        int n=a.size();
        int lmax=a[0],rmax=a[n-1];
        int l=1,r=n-2;
        int res=0;
        while(l<=r){
            //trap water now based on height of left side
            if(lmax<rmax){
                if(lmax<a[l]) lmax=a[l]; //update left boundary
                else res+=lmax-a[l];
                l++;
            }
            else {
                if(rmax<a[r]) rmax=a[r]; //update right boundary
                else res+=rmax-a[r];
                r--;
            }
        }
        return res;
    }
};

