class Solution {
public:
    //time O(n)
    //space O(1)
    long long minOperations(vector<int>& a, vector<int>& b, int k) {
        if(a==b) return 0; //no opertion needed
        if(k==0) return -1; //else there is no changed 
        
        long long res=0;
        int n=a.size();
        long long count=0; //count how many operations need to make equality
        int i=0;
        while(i<n){
            if(a[i]>b[i]){ 
                int temp=a[i]-b[i];
                if(temp%k==0) //num1 and num2 must be differential by K value
                    count+=((a[i]-b[i])/k); //increasing operations
                res=count; //update result when decreasing needed
            }
            i++;
        }
        i=0;
        //if exist operation
        while(count && i < n){
            if(a[i]<b[i]){
                count-=(b[i]-a[i])/k;
            }
            i++;
        }
        // we have eliminate the none-operation, so there must be at least an operation 
        // which incre and decre should be the same
        // check the res condition to avoid all element are smaller
        if(res && count==0) return res;
        // if there is any action left (count!=0), return -1;
        return -1;
    }
};