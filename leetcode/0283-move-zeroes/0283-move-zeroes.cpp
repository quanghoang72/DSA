class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        if(n==1) return;
        int temp=0;
        for(int i=0;i<n;i++){
            while(temp<n && a[temp]==0) temp++;
            if(temp >= n) break;
            swap(a[i],a[temp++]);
        }
    }
};