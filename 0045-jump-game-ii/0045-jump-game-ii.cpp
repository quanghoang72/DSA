class Solution {
public:
    //time O(n)
    //space O(1)
    int jump(vector<int>& a){
        int n=a.size();
        int l=0,r=0;
        int res=0;
        int furthest=0;
        while(r<n-1){
            for(int i=l;i<r+1;i++){
                furthest=max(furthest,i+a[i]);
            }
            l=r+1;
            r=furthest;
            res++;
        }
        return res;
    }
};