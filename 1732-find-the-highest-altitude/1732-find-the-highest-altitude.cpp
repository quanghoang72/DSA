class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0,sum=0;
        for(int val:gain){
            sum+=val;
            res=max(res,sum);
        }
        return res;
    }
};