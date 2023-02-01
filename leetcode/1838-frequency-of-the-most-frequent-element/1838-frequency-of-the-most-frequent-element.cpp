class Solution {
public:
    //time O(nlogn)
    //space O(1)
    //cant use K to decrease the number so the number must be sorted
    // and traverse from l->r to increase the number base on the right bound
    // try to have the most frequent number by make all the number in window are the same
    int maxFrequency(vector<int>& a, long long k) {
        sort(a.begin(),a.end());
        int l=0;
        int r=0;
        int res=0;
        long long total=0;
        while(r<a.size()){
            total+=a[r];

            //invalid window
            while((long)(r-l+1)*a[r] > total+k){
                total-=a[l];
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};