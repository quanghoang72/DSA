class Solution {
public:
    //time O(n)
    //space O(1)
    int countOrders(int n) {
        if(n==1)
            return 1;
        long long res=0;
        long long prev=1;
        for(int i=2;i<=n;i++){
            int sz=i*2-1;
            res=i*sz*prev;
            res%=1000000007;
            prev=res;
            
        }
        return res;
    }
};