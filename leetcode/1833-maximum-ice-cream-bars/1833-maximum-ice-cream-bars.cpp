class Solution {
public:
    int maxIceCream(vector<int>& a, int sum) {
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            sum-=a[i];
            if(sum<0) return i;
        }
        return n;
    }
};