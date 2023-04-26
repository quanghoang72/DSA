class Solution {
public:
    //time O(1)
    //space O(1)
    int addDigits(int a) {
        return a==0 ? 0 : a%9==0 ? 9 : a%9;
    }
};