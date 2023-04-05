class Solution {
public:
    //time O(NlogN)
    //space O(1)
    int minimizeArrayValue(vector<int>& a) {
        int r=*max_element(a.begin(),a.end());
        int l=0;
        int n=a.size();
        while(l<r){
            int m=l+(r-l)/2;
            long long carry=0;
            for(int i=n-1;i>=0;i--){
                long long temp=a[i];
                temp+=carry;
                carry= temp>m ? temp-m : 0;
            }
            if(carry==0) r=m;
            else l=m+1;
            
        }
        return l;
    }
};