class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((int)log2(n)==log2(n)) return true;
        return false;
    }
};