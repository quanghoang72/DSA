class Solution {
public:
    double myPow(double x, int n) {
        int exponent=abs(n);
        return n >= 0 ? helper(x,exponent) : 1/helper(x,exponent);
    }
private:
    double helper(double x,int n){
        if(n==0) return 1;
        if(x==0) return 0;
        double result= myPow(x*x,n/2);
        if(n%2==0) 
            return result;
        return result*x;
    }
};