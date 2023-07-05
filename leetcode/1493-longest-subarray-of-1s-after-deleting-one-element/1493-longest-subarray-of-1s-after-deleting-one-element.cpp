class Solution {
public:
    //time O(n)
    //space O(1)
    int longestSubarray(vector<int>& a) {
        int l=0,r=0;
        int n=a.size();
        int del=0;
        int res=0;
        while(r<n){
                if(a[r]!=1) del++;
                if(del>1){
                    
                    while(l<r && a[l]==1){
                        l++;
                    }
                    while(l<r && a[l]==0){
                        l++;
                        del--;
                    }
                }
                res=max(res,r-l);
                r++;
        }
            return res;
    }
};