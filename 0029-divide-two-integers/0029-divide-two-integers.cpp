class Solution {
public:
    //time O(logn)
    //space O(1)
    
    // a / b -> quotient * b + reminder
    // quotient is represented as power of 2 (11=2^3 + 2^1 + 2^0)
    // multiply divisor with the maximum power of 2 
    // repeat until diviend is smaller than divisors
    // the quotient result will be the maximum number of power of 2
    int divide(int a, int b) {
        if(b==-1 && a==INT_MIN) return INT_MAX;
        if(a==b) return 1;
        bool sign= (a>=0) == (b>=0) ? true : false;
        unsigned int res=0;
        unsigned int x=abs(a);
        unsigned int y=abs(b);
        while(x >= y){
            int q=0;
            while(x > (unsigned int)(y << q << 1 )){ //find max power of 2
                q++;
            }
            res+= (1<<q); //add power of 2 found to result
            x= x - (y<<q); //reduce dividend
        }
        return sign? res : -res;
    }
};