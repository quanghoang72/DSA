class Solution {
public:
    int search(vector<int>& a, int t) {
        int l=0,h=a.size();
        while(l<h){
            int m =(l+h)/2;
            // both target and mid on the right side
            if((t<a[0])==(a[m]<a[0])){
                if(a[m]==t) return m;
                else if(a[m]> t) h=m;
                else l=m+1;
            }
            //opposite side
            else if(t<a[0]) l=m+1;
            //both on the left side >a[0]
            else h=m;
        }
        return -1;
    }
};