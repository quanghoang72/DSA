class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n=a.size();
        vector<int> res(n,0);
        if(n==1) return {a[0]*a[0]};
        int i=0,j=n-1;
        int idx=n-1;
        while(i<=j && idx>=0){
            if(abs(a[i])<abs(a[j])) res[idx--]=a[j]*a[j--];
            else res[idx--]=a[i]*a[i++];
        }
        return res;
    }
};
