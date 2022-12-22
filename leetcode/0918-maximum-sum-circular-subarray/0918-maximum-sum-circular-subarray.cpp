class Solution {
public:
    //time O(n)
    //space O(1)
    int maxSubarraySumCircular(vector<int>& a) {
        //kadane algorithm to find max and min
        //array is circular the max might be in normal case (not circular)
        //in normal case --> simple kadane algorithm to find max
        //in circular --> totalsum - minsum = maxsum
        int n=a.size();
        if(n==1) return a[0];
        int sum=a[0];
        int minsofar=a[0],curmin=a[0];
        int maxsofar=a[0],curmax=a[0];
        for(int i=1;i<n;i++){
            curmax=max(curmax+a[i],a[i]);
            curmin=min(curmin+a[i],a[i]);
            
            maxsofar=max(curmax,maxsofar);
            minsofar=min(curmin,minsofar);
            sum+=a[i];
        }
        
        //if sum==minsofar then all element are negative we return the max
        if(minsofar==sum) return maxsofar;
        return max(maxsofar,sum-minsofar);
    }
};
