class Solution {
public:
    int reverse(int x) {
        long int res=0;
        while(x){
            //check before multiply by 10
            if(res < INT_MIN/10 || res > INT_MAX/10 ) return 0;
            long int temp=res*10+ x%10;
            res=temp;
            x/=10;
        }
        //test ci
        return res;
    }
};