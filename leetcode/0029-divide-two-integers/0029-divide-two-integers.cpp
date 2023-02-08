class Solution {
public:
    int divide(int a, int b) {
        if(b==-1 && a==INT_MIN) return INT_MAX;
        if(a==b) return 1;
        bool sign= (a>=0) == (b>=0) ? true : false;
        unsigned int res=0;
        unsigned int x=abs(a);
        unsigned int y=abs(b);
        while(x >= y){
            int q=0;
            while(x > (unsigned int)(y << q << 1 )){
                q++;
            }
            res+= (1<<q);
            x= x - (y<<q);
        }
        return sign? res : -res;
    }
};