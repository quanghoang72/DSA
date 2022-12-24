class Solution {
public:
    //time O(n)
    //space O(1)
    int maxProfit(vector<int>& a) {
        int min=a[0];
        int pro=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<min)min=a[i];
            else if(a[i]-min > pro) pro=a[i]-min;
        }
        return pro;
    }
};