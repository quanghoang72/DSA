class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int res=0;
        for(int i=n-1;i>1;i--){
            int l=0,r=i-1;
            while(l<r){
                int tmp=a[l]+a[r];
                //if valid triangle 
                if(tmp>a[i]){
                    //all the element in this range will be accpted as a triangle
                    res+=r-l;
                    
                    // to check any possible left
                    r--; 
                }
                //two other side is too small
                //increase the left side
                else l++;
            }
        }
        return res;
    }
};