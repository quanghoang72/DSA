class Solution {
public:
    //time O(n)
    //space O(1);
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        if(n==1) return 1;
        int idx=1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1])
                a[idx++]=a[i];
        }
        return idx;
    }
};