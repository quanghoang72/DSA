class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int max_current=0;
        int max_sofar=INT_MIN;
        for(int i=0;i<a.size();i++){
            max_current+=a[i];
            max_sofar=max(max_sofar,max_current);
            if(max_current < 0) max_current=0;
        }
        return max_sofar;
    }
};
