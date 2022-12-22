class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        //base on min(n,m);
        if(n>m) 
            return findMedianSortedArrays(b,a);
        int l=0,r=n;
        int total=m+n;
        //imaginary meadian position
        int half=(total+1)/2;
        while(l<=r){
            //current meadian for first half
            int i=(l+r)/2;
            //other cut suppose to be
            int j=half-i;
            //-1 for the index position
            int aL= i>0 ? a[i-1] : INT_MIN;
            int aR= i<n ? a[i] : INT_MAX;
            int bL= j>0 ? b[j-1] : INT_MIN;
            int bR= j<m ? b[j] : INT_MAX;
            
            if(aL <= bR && bL <= aR){
                if(total&1) //ood length
                    return max(aL,bL);
                return ((min(aR,bR)+max(aL,bL))/2.0); //even length
            }
            else if(aL > bR) r=i-1;
            else l=i+1;
        }
        return -1;
    }
};