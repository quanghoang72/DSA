class Solution {
public:
    int shipWithinDays(vector<int>& a, int k) {
        int mx=*max_element(a.begin(),a.end());
        int l=mx;
        int r=accumulate(a.begin(),a.end(),0);
        int res=INT_MAX;
        while(l<=r){
            int m=l+ceil((r-l)*1.0/2);
            int day=1;
            int temp=a[0];
            int i;
            for(i=1;i<a.size();i++){
                if(temp+a[i]>m){
                    day++;
                    temp=a[i];
                    continue;
                }
                temp+=a[i];
            }
            if(day>k)
                l=m+1;
            else {
                res=min(res,m);
                r=m-1;
            }
        }
        return res;
    }
};