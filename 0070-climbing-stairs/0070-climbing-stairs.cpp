class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        int res=0;
        for(int i=3;i<=n;i++){
            res=first+second;
            first=second;
            second=res;
        }
        return n <=2 ? n : res;

    }
};
