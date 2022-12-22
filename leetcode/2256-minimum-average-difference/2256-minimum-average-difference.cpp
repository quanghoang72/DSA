class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n=a.size();
        long sum=0,cursum=0;
        int res=0,tmp=INT_MAX;
        for(auto x : a) sum+=x;
        for(int i=0;i<n;i++){
            cursum+=a[i];
            sum-=a[i];
            int front = cursum / (i+1);
            int back  = i==n-1 ?  0 : sum / (n-i-1);
            if(abs(front-back)<tmp){
                res=i;
                tmp=abs(front-back);
            }
        }
        return res;
    }
};