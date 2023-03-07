class Solution {
public:
    //time O(n)
    //space O(1)
    long long minimumTime(vector<int>& a, int k) {
        long long l=*min_element(a.begin(),a.end());
        long long r=l*k;
        long long res=r;
        while(l<=r){
            long long m=l+ (r-l)/2;
            long long trip=0;
            for(int i=0;i<a.size();i++){
                trip+=m/a[i];
            }
            if(trip >= k) {
                r=m-1;
                res=min(res,m);
            }
            else l=m+1;
        }
        return res;
    }
};

