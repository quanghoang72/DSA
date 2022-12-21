class Solution {
public:
    int helper(vector<int> &a,int start,int n){
        int rob1=0,rob2=0;
        for(int i=start;i<=n;i++){
            int temp=max(rob1+a[i],rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
    int rob(vector<int>& a) {
        int n=a.size();
        if(n<2) return n? a[0] :0;
        //compare max of
        // house 1 to n-1
        // house 2 to n-2
        // since house 0 and n-1 are neighbor
        return max(helper(a,1,n-1),helper(a,0,n-2));
    }
};
