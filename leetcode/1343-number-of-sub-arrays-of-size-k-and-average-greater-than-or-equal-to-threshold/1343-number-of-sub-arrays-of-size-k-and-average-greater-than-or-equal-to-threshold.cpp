class Solution {
public:
    //time O(n)
    //space O(1)
    int numOfSubarrays(vector<int>& a, int k, int threshold) {
        int n=a.size();
        double average=0.0;
        int res=0;
        int sum=0;
        int l=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(i>=k-1){
                average=sum/k;
                if(average >= threshold) res++;
                sum-=a[l++];
            }
        }
        return res;
    }
};