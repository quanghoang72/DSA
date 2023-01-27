class Solution {
public:
    //time O(n^2)
    //space O(1)
    int threeSumClosest(vector<int>& a, int target) {
        if(a.size()==3) return a[0]+a[1]+a[2];
        int diff=INT_MAX;
        int n=a.size();
        int res=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int tmp=a[l]+a[i]+a[r];
                if(abs(tmp-target) < diff){
                    res=tmp;
                    diff=abs(tmp-target);
                }
                if(tmp==target) return tmp;
                else if(tmp > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
    }
};