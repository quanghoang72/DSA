class Solution {
public:
    int maxProfit(vector<int>& a) {
        int res=0;
        for(int i=1;i<a.size();i++){
            //curernt price > last price
            if(a[i]>a[i-1])
                res+=a[i]-a[i-1];
        }
        return res;
    }
};